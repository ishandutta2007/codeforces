#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxq=2e5+10,maxn=5e5,maxbit=19;
int n,q,f[maxbit+1][maxn+10];
pii dt[maxq];
vector<pii> d;
void read()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++) scanf("%d %d",&dt[i].fi,&dt[i].se);
}

void compress()
{
    sort(dt+1,dt+1+n);
    int mx=dt[1].se;
    for (int i=2;i<=n;i++)
        if (dt[i].fi==dt[i-1].fi) mx=max(mx,dt[i].se);
        else
        {
            if (d.empty() || mx>d.back().se) d.pb({dt[i-1].fi,mx});
            mx=dt[i].se;
        }
    if (d.empty() || mx>d.back().se)  d.pb({dt[n].fi,mx});
}

void build()
{
    for (int i=1;i<=maxbit;i++)
        for (int j=0;j<=maxn;j++) f[i][j]=-1;
    d.pb({d.back().se+1,0});
    for (int i=0;i<d.size()-1;i++)
        for (int j=d[i].fi;j<=min(d[i].se,d[i+1].fi-1);j++) f[0][j]=d[i].se;
    for (int k=1;k<=maxbit;k++)
        for (int i=0;i<=maxn;i++)
            if (f[k-1][i]!=-1 && f[k-1][f[k-1][i]]!=-1) f[k][i]=f[k-1][f[k-1][i]];
}

int bs(int x,int y)
{
    int k=0,ans=0;
    while (k<20 && f[k][x]!=-1 && f[k][x]<y) k++;
    if (k==20 || f[k][x]==-1) return -1;
    if (k==0) return ans+1;
    //if (f[k][x]==y) return ans+(1<<k);
    k--;
    while (x<=y)
    {
        ans+=1<<k;
        x=f[k][x];
        if (x>=y) return ans;
        while (k>=0 && f[k][x]>=y) k--;
        if (k==-1) return ans+1;
    }
    return ans;
}

void process()
{
    int x,y;
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d",&x,&y);
        int tmp=bs(x,y);
        printf("%d \n",tmp);
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    compress();
    build();
    //for (int i=0;i<d.size();i++) cout<<d[i].fi<<" "<<d[i].se<<endl;
    process();
    return 0;
}