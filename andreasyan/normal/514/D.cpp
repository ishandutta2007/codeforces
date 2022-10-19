#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n,m,k;
int a[N][5];

int t[N*4][5];
void bil(int tl,int tr,int pos)
{
    if(tl==tr)
    {
        for(int i=0;i<m;++i)
            t[pos][i]=a[tl][i];
        return;
    }
    int mid=(tl+tr)/2;
    bil(tl,mid,pos*2);
    bil(mid+1,tr,pos*2+1);
    for(int i=0;i<m;++i)
        t[pos][i]=max(t[pos*2][i],t[pos*2+1][i]);
}
int qry(int tl,int tr,int l,int r,int i,int pos)
{
    if(tl==l && tr==r)
        return t[pos][i];
    int mid=(tl+tr)/2;
    if(r<=mid)
        return qry(tl,mid,l,r,i,pos*2);
    else if(l>mid)
        return qry(mid+1,tr,l,r,i,pos*2+1);
    else
        return max(qry(tl,mid,l,mid,i,pos*2),qry(mid+1,tr,mid+1,r,i,pos*2+1));
}

bool stg(int x)
{
    if(x==0)
        return true;
    for(int r=x;r<=n;++r)
    {
        int l=(r-x+1);
        int yk=k;
        for(int i=0;i<m;++i)
        {
            yk-=qry(1,n,l,r,i,1);
        }
        if(yk>=0)
            return true;
    }
    return false;
}

int byn()
{
    int l=0,r=n;
    while((r-l)>=4)
    {
        int mid=(l+r)/2;
        if(stg(mid))
            l=mid;
        else
            r=mid;
    }
    for(int i=r;i>=l;--i)
        if(stg(i))
            return i;
}

int main()
{
    //freopen("span.in","r",stdin);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
            cin>>a[i][j];
    bil(1,n,1);
    int x=byn();
    if(x==0)
    {
        for(int i=0;i<m;++i)
            cout<<0<<' ';
        cout<<endl;
        return 0;
    }
    for(int r=x;r<=n;++r)
    {
        int ans[5]={};
        int l=(r-x+1);
        int yk=k;
        for(int i=0;i<m;++i)
        {
            int q=qry(1,n,l,r,i,1);
            ans[i]=q;
            yk-=q;
        }
        if(yk>=0)
        {
            for(int i=0;i<m;++i)
                cout<<ans[i]<<' ';
            cout<<endl;
            return 0;
        }
    }
    return 0;
}