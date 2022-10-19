#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N=100003;
struct ban
{
    int l,r;
    long long v;
};

int n,q,k;
long long a[N];
ban b[N];
long long c[N];
long long t[N*4];
void ubd(int tl,int tr,int l,int r,int pos,long long v)
{
    if(tl==l && tr==r)
    {
        t[pos]+=v;
        return;
    }
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
}
long long qry(int tl,int tr,int pos,int x)
{
    if(tl==tr)
        return t[pos];
    int m=(tl+tr)/2;
    if(x<=m)
        return t[pos]+qry(tl,m,pos*2,x);
    else
        return t[pos]+qry(m+1,tr,pos*2+1,x);
}
int main()
{
    cin>>n>>q>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=q;++i)
        cin>>b[i].l>>b[i].r>>b[i].v;
    for(int i=0;i<k;++i)
    {
        int l,r;
        cin>>l>>r;
        c[l]++;
        c[r+1]--;
    }
    long long h=0;
    for(int i=1;i<=q;++i)
    {
        h+=c[i];
        ubd(1,n,b[i].l,b[i].r,1,h*b[i].v);
    }
    for(int i=1;i<=n;++i)
        cout<<a[i]+qry(1,n,1,i)<<' ';
    return 0;
}