#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,r,m;
    cin >> n >> a >> r >> m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    ll x=0;
    ll y=0;
    for(int i=0;i<n;i++) y+=(v[i]-v[0]);
    ll cnt=0;
    ll idx=0;
    ll res=y*r;
    while(idx<n)
    {
        cnt++;
        while(idx<n&&v[idx+1]==v[idx])
        {
            idx++;
            cnt++;
        }
        if(idx==n-1) break;
        idx++;
        x+=(cnt*(v[idx]-v[idx-1]));
        y-=((n-cnt)*(v[idx]-v[idx-1]));
        ll k=min(x,y);
        res=min(res,min(x*a+y*r,(x-k)*a+(y-k)*r+k*m));
    }
    ll one=0,two=v[n-1]+1;
    while(one<two-1)
    {
        ll mid=(one+two)/2;
        ll xnow=0;
        ll ynow=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]<=mid) xnow+=(mid-v[i]);
            else ynow+=(v[i]-mid);
        }
        if(xnow<=ynow) one=mid;
        else two=mid;
    }
    auto solve=[&](ll h)->void
    {
        ll xnow=0;
        ll ynow=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]<=h) xnow+=(h-v[i]);
            else ynow+=(v[i]-h);
        }
        ll know=min(xnow,ynow);
        res=min(res,min(xnow*a+ynow*r,(xnow-know)*a+(ynow-know)*r+know*m));
    };
    solve(one);
    solve(one+1);
    cout << res << "\n";
    return 0;
}