#include <iostream>
using namespace std;
const int N=100005;

int n,q;
int a[N];
long long c[N*4],t[N*4];
void sh(int pos)
{
    if(c[pos]!=-1)
    {
        c[pos*2]=c[pos];
        c[pos*2+1]=c[pos];
        t[pos*2]=c[pos];
        t[pos*2+1]=c[pos];
        c[pos]=-1;
    }
}
void ubd(int tl,int tr,int l,int r,int pos,long long v)
{
    if(tl==l && tr==r)
    {
        c[pos]=v;
        t[pos]=v;
        return;
    }
    sh(pos);
    int m=(tl+tr)/2;
    if(r<=m)
        ubd(tl,m,l,r,pos*2,v);
    else if(l>m)
        ubd(m+1,tr,l,r,pos*2+1,v);
    else
    {
        ubd(tl,m,l,m,pos*2,v);
        ubd(m+1,tr,m+1,r,pos*2+1,v);
    }
    t[pos]=max(t[pos*2],t[pos*2+1]);
}
long long qry(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
        return t[pos];
    sh(pos);
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(tl,m,l,r,pos*2);
    else if(l>m)
        return qry(m+1,tr,l,r,pos*2+1);
    else
        return max(qry(tl,m,l,m,pos*2),qry(m+1,tr,m+1,r,pos*2+1));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ubd(1,n,i,i,1,a[i]);
    }
    cin>>q;
    for(int i=0;i<q;++i)
    {
        int w,h;
        cin>>w>>h;
        long long v=qry(1,n,1,w,1);
        cout<<v<<endl;
        v+=h;
        ubd(1,n,1,w,1,v);
    }
    return 0;
}