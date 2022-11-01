#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> b(n+1,0);
    auto go=[&](ll lim)->ll
    {
        ll c=0;
        for(int i=1;i<=n;i++)
        {
            ll l=0,r=a[i]+1;
            while(l<r-1)
            {
                ll m=(l+r)/2;
                if(a[i]-(3*m*m-3*m+1)>=lim) l=m;
                else r=m;
            }
            b[i]=l;
            c+=b[i];
        }
        return c;
    };
    ll l=-(1ll<<60),r=(1ll<<60);
    for(int i=1;i<=n;i++)
    {
        l=max(l,a[i]-1+1);
        r=min(r,a[i]-(3*a[i]*a[i]-3*a[i]+1)-1);
    }
    while(l>r+1)
    {
        ll m=(l+r)/2;
        if(go(m)<=k) l=m;
        else r=m;
    }
    ll t=k-go(l);
    for(int i=1;i<=n;i++)
    {
        if(t>0&&b[i]<a[i]&&(a[i]-(3*(b[i]+1)*(b[i]+1)-3*(b[i]+1)+1))==l-1)
        {
            b[i]++;
            t--;
        }
        cout << b[i] << " \n"[i==n];
    }
    return 0;
}