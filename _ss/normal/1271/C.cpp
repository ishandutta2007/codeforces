#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;
pii a[N];
int n,x,y;

int check(int t1,int t2,int t3)
{
    if (t1<=t2 && t2<=t3) return true;
    if (t1>=t2 && t2>=t3) return true;
    return false;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x>>y;
    for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
    int res=0,tx=0,ty=0;
    for (int i=-1;i<=1;i++)
        for (int j=-1;j<=1;j++)
        {
            int u=x+i;
            int v=y+j;
            if (u==x && v==y) continue;
            int sl=0;
            for (int t=1;t<=n;t++)
                if (check(a[t].fi,u,x) && check(a[t].se,v,y)) sl++;
            if (sl>res)
            {
                res=sl;
                tx=u;
                ty=v;
            }
        }
    cout<<res<<"\n"<<tx<<" "<<ty;
    return 0;
}