#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5,mod=1e9+7,inf=1e18;

struct ds {int x,t,id; };
int n,w,h;
pii ans[maxn+10];

vector<ds> ver[2*maxn+10],hor[2*maxn+10];

void read()
{
    cin>>n>>w>>h;
    int g,p,t;
    for (int i=1;i<=n;i++)
    {
        cin>>g>>p>>t;
        if (g==1) ver[p-t+maxn].pb({p,t,i});
        else hor[p-t+maxn].pb({p,t,i});
    }
}

bool cmp(ds obj1, ds obj2) { return obj1.x<obj2.x; }

void process()
{
    for (int i=0;i<=2*maxn;i++)
    {
        sort(all(ver[i]),cmp);
        sort(all(hor[i]),cmp);
        int siz1=ver[i].size(),siz2=hor[i].size();
        for (int j=0;j<ver[i].size();j++)
        {
            int x=siz1-j-1;
            int y=siz2;
            if (x<y) ans[ver[i][j].id]=mp(w,hor[i][x].x);
            else ans[ver[i][j].id]=mp(ver[i][j+y].x,h);
        }
        for (int j=0;j<hor[i].size();j++)
        {
            int x=siz1;
            int y=siz2-j-1;
            if (y<x) ans[hor[i][j].id]=mp(ver[i][y].x,h);
            else ans[hor[i][j].id]=mp(w,hor[i][j+x].x);
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}