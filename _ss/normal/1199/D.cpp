#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+100;

int a[maxn],n,q,lazy[maxn*4];

void down(int st)
{
    int v=lazy[st];
    lazy[st*2]=max(lazy[st*2],v);
    lazy[st*2+1]=max(lazy[st*2+1],v);
    lazy[st]=0;
}

void update(int st,int l,int r,int v,int x)
{
    if (l>v && r<v) return;
    if (l==r)
    {
        if (x!=-1)
        {
        a[l]=x;
        lazy[st]=0;
        }
        else a[l]=max(a[l],lazy[st]);
        return;
    }
    down(st);
    int mid=(l+r)/2;
    if (v<=mid) update(st*2,l,mid,v,x);
    else update(st*2+1,mid+1,r,v,x);
}

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
}

void process()
{
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        int t,p,x;
        scanf("%d",&t);
        if (t==1)
        {
            scanf("%d %d",&p,&x);
            update(1,1,n,p,x);
        }
        else
        {
            scanf("%d",&x);
            lazy[1]=max(x,lazy[1]);
            //down(1);
        }
    }
    //for (int i=1;i<n*2;i++) cout<<lazy[i]<<endl;
    for (int i=1;i<=n;i++) update(1,1,n,i,-1);
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}