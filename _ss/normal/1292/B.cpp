#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=3e16;
pii a[N],vs;
ll n=1,ax,ay,bx,by,t;

ll dis(pii p1,pii p2)
{
    return abs(p1.fi-p2.fi)+abs(p1.se-p2.se);
}

ll best(pii p0,pii p1,pii p2)
{
    return min(dis(p0,p1),dis(p1,p2))+dis(p0,p1)+dis(p1,p2);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a[1].fi>>a[1].se>>ax>>ay>>bx>>by>>vs.fi>>vs.se>>t;
    while (a[n].fi<=inf && a[n].se<=inf)
    {
        n++;
        a[n].fi=a[n-1].fi*ax+bx;
        a[n].se=a[n-1].se*ay+by;
    }
    int res=0;
    for (int i=1;i<=n;i++)
        for (int l=1;l<=i;l++)
            for (int r=i;r<=n;r++)
                if (dis(vs,a[i])+best(a[l],a[i],a[r])<=t) res=max(res,r-l+1);
    cout<<res;
    return 0;
}