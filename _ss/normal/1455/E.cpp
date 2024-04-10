#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;

ll cost(vector<pll> vt)
{
    ll x1=vt[0].fi,x2=vt[1].fi,x3=vt[2].fi,x4=vt[3].fi;
    if (x1>x2) swap(x1,x2);
    if (x3>x4) swap(x3,x4);
    ll cx=x2-x1+x4-x3;
    ll lx,rx;
    lx=max(max(x1,x3)-min(x2,x4),(ll)0);
    rx=max(x2,x4)-min(x1,x3);

    ll y1=vt[0].se,y2=vt[2].se,y3=vt[1].se,y4=vt[3].se;
    if (y1>y2) swap(y1,y2);
    if (y3>y4) swap(y3,y4);
    ll cy=y2-y1+y4-y3;
    ll ly,ry;
    ly=max(max(y1,y3)-min(y2,y4),(ll)0);
    ry=max(y2,y4)-min(y1,y3);
    ll c=cx+cy+max((ll)0,max(lx,ly)-min(rx,ry))*2;
    return c;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        vector<pll> vt;
        for (int i=1,x,y;i<=4;i++) cin>>x>>y,vt.eb(mp(x,y));
        ll res=1e18;
        for (int i=1;i<=24;i++)
        {
            res=min(res,cost(vt));
            next_permutation(all(vt));
        }
        cout<<res<<"\n";
    }
    return 0;
}