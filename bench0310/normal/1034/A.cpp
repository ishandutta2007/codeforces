#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=15000000;
    vector<int> p(N+1);
    for(int i=0;i<=N;i++) p[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(p[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) p[j]=min(p[j],(int)i);
    }
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> m;
    int g=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        g=gcd(g,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        a[i]/=g;
        while(a[i]>1)
        {
            int x=p[a[i]];
            m[x]++;
            while(p[a[i]]==x) a[i]/=x;
        }
    }
    int res=n;
    for(auto [prime,cnt]:m) res=min(res,n-cnt);
    if(res==n) res=-1;
    cout << res << "\n";
    return 0;
}