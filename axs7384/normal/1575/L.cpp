#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t[N*4];
struct dt
{
    int x,id;
    bool operator<(const dt&a)const
    {
        return id-x!=a.id-a.x?id-x<a.id-a.x:x<a.x;
    }
}f[N];
int n,m;
/*inline void build(int x,int l,int r)
{
    t[x]=-1;
    if (l==r)
        return;
    int mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
}*/
inline int ask(int x,int l,int r,int L,int R)
{
    if (l==L&&r==R)
        return t[x];
    int mid=(l+r)/2;
    if (R<=mid)
        return ask(x*2,l,mid,L,R);
    if (L>mid)
        return ask(x*2+1,mid+1,r,L,R);
    return max(ask(x*2,l,mid,L,mid),ask(x*2+1,mid+1,r,mid+1,R));
}
inline void modify(int x,int l,int r,int p,int y)
{
    t[x]=max(t[x],y);
    if (l==r)
        return;
    int mid=(l+r)/2;
    if (p<=mid)
        modify(x*2,l,mid,p,y);
    else
        modify(x*2+1,mid+1,r,p,y);
}
int main()
{
    scanf("%d",&n);
    for (int i=1,x;i<=n;++i)
    {
        scanf("%d",&x);
        if (x<=i)
            f[++m]={x,i};
    }
    //build(1,1,n);
    sort(f+1,f+1+m);
    for (int i=1;i<=m;++i)
    {
        //cout<<f[i].x<<' '<<f[i].id<<endl;
        int p=(f[i].x==1?0:ask(1,1,n,1,f[i].x-1));
        modify(1,1,n,f[i].x,p+1);
    }
    cout<<t[1]<<endl;
    return 0;
}