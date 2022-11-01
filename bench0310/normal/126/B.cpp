#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    const ll mod=rng(100000000,2000000000);
    const ll p=31;
    vector<ll> pw(n+1,1);
    for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*p)%mod;
    vector<ll> x(n+1,0);
    for(int i=1;i<=n;i++) x[i]=(p*x[i-1]+(s[i]-'a'))%mod;
    auto h=[&](int l,int r)->ll
    {
        ll y=x[r];
        y=(y-pw[r-(l-1)]*x[l-1])%mod;
        if(y<0) y+=mod;
        return y;
    };
    int mx=0;
    for(int i=2;i<n;i++)
    {
        int l=i-1,r=n;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(h(i,m)==h(1,m-i+1)) l=m;
            else r=m;
        }
        mx=max(mx,l-i+1);
    }
    int res=0;
    for(int i=1;i<=mx;i++) if(h(1,i)==h(n-i+1,n)) res=i;
    if(res>0) cout << s.substr(1,res) << "\n";
    else cout << "Just a legend\n";
    return 0;
}