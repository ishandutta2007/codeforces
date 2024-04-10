#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    int res=n;
    for(int i=0;i<30;i++)
    {
        int x=rng(1,n);
        vector<ll> primes;
        for(ll b=a[x]-1;b<=a[x]+1;b++)
        {
            ll t=b;
            for(ll j=2;j*j<=t;j++)
            {
                if((t%j)!=0) continue;
                primes.push_back(j);
                while((t%j)==0) t/=j;
            }
            if(t>1) primes.push_back(t);
        }
        for(ll p:primes)
        {
            ll now=0;
            for(int j=1;j<=n;j++) now+=min((a[j]>=p?a[j]%p:p),p-(a[j]%p));
            res=min((ll)res,now);
        }
    }
    cout << res << "\n";
    return 0;
}