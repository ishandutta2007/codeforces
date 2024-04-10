#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=2e5+10,inf=1e18;

int n,m,q,hv[maxn],nextt[maxn],a[maxn],p[maxn],dd[maxn],tt[maxn][50],b[maxn],it[maxn*4];

void build(int st,int l,int r)
{
    if (l==r)
    {
        it[st]=b[l];
        return;
    }
    int mid=(l+r)/2;
    build(st*2,l,mid);
    build(st*2+1,mid+1,r);
    it[st]=min(it[st*2],it[st*2+1]);
}

ll get(int st,int l,int r,int u,int v)
{
    if (l>v || r<u) return inf;
    if (u<=l && r<=v) return it[st];
    int mid=(l+r)/2;
    return min(get(st*2,l,mid,u,v),get(st*2+1,mid+1,r,u,v));
}

int tiento(int x,int h)
{
    vector<int> gt;
    while (h) gt.push_back(h%2),h/=2;
    for (int i=gt.size()-1;i>=0;i--)
        if (gt[i]) x=tt[x][i];
    return x;
}
int main()
{
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++) cin>>hv[i];
    for (int i=1;i<n;i++) nextt[hv[i]]=hv[i+1];
    nextt[hv[n]]=hv[1];
    for (int i=1;i<=m;i++) cin>>a[i];
    p[m+1]=m+1;
    for (int i=1;i<=n;i++) dd[i]=m+1;
    for (int i=m;i;i--)
    {
        p[i]=dd[nextt[a[i]]];
        dd[a[i]]=i;
    }
    int k=n,h=0;
    while (k) k/=2,h++;
    for (int i=0;i<=h;i++) tt[m+1][i]=m+1;
    for (int i=1;i<=m;i++) tt[i][0]=p[i];
    for (int j=1;j<=h;j++)
        for (int i=m;i;i--) tt[i][j]=tt[tt[i][j-1]][j-1];
    for (int i=1;i<=m;i++) b[i]=tiento(i,n-1);
    build(1,1,m);
    int u,v;
    for (int i=1;i<=q;i++)
    {
        cin>>u>>v;
        if (get(1,1,m,u,v)<=v) cout<<1; else cout<<0;
    }
}