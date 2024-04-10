#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        int m;
        cin >> n >> m;
        vector<ll> tmp(m);
        vector<array<ll,2>> a(m);
        vector<array<ll,2>> b(m);
        for(int i=0;i<m;i++)
        {
            cin >> a[i][0] >> b[i][0];
            a[i][1]=b[i][1]=i;
            tmp[i]=a[i][0];
        }
        sort(a.begin(),a.end(),greater<array<ll,2>>());
        sort(b.begin(),b.end(),greater<array<ll,2>>());
        ll res=0;
        for(int i=0;i<min((int)n,m);i++) res+=a[i][0];
        vector<bool> v(m,0);
        int idx=0;
        ll now=0;
        for(auto [val,id]:b)
        {
            while(idx+2<=n&&idx<m&&a[idx][0]>=val)
            {
                now+=a[idx][0];
                v[a[idx][1]]=1;
                idx++;
            }
            ll x=now;
            ll c=n-idx;
            if(v[id]==0)
            {
                x+=tmp[id];
                c--;
            }
            x+=(val*c);
            res=max(res,x);
        }
        cout << res << "\n";
    }
    return 0;
}