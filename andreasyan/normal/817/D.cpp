#include <bits/stdc++.h>
using namespace std;
const int N=1000006;
struct ban
{
    long long laz;
    long long sum;
    ban()
    {
        laz=sum=0;
    }
};

int n;
int a[N];

vector<ban> maxu,minu;

void shi(vector<ban>& t,int l,int r,int pos)
{
    if(t[pos].laz==-1)
        return;
    int m=(l+r)/2;
    t[pos*2].laz=t[pos].laz;
    t[pos*2+1].laz=t[pos].laz;
    t[pos*2].sum=(m-l+1)*t[pos].laz;
    t[pos*2+1].sum=(r-m)*t[pos].laz;
    t[pos].laz=-1;
}

void ubd(vector<ban>& t,int tl,int tr,int l,int r,long long x,int pos)
{
    if(tl==l && tr==r)
    {
        t[pos].laz=x;
        t[pos].sum=x*(r-l+1);
        return;
    }
    shi(t,tl,tr,pos);
    int m=(tl+tr)/2;
    if(r<=m)
        ubd(t,tl,m,l,r,x,pos*2);
    else if(l>m)
        ubd(t,m+1,tr,l,r,x,pos*2+1);
    else
    {
        ubd(t,tl,m,l,m,x,pos*2);
        ubd(t,m+1,tr,m+1,r,x,pos*2+1);
    }
    t[pos].sum=t[pos*2].sum+t[pos*2+1].sum;
}

long long qry(vector<ban>& t,int tl,int tr,int l,int r,int pos)
{
    if(t[pos].laz!=-1)
        return (r-l+1)*t[pos].laz;
    if(tl==l && tr==r)
        return t[pos].sum;
    shi(t,tl,tr,pos);
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(t,tl,m,l,r,pos*2);
    if(l>m)
        return qry(t,m+1,tr,l,r,pos*2+1);
    return qry(t,tl,m,l,m,pos*2)+qry(t,m+1,tr,m+1,r,pos*2+1);
}

int maxt[N*4];

void ubdmax(int tl,int tr,int x,int i,int pos)
{
    if(tl==tr)
    {
        maxt[pos]=i;
        return;
    }
    int m=(tl+tr)/2;
    if(x<=m)
        ubdmax(tl,m,x,i,pos*2);
    else
        ubdmax(m+1,tr,x,i,pos*2+1);
    maxt[pos]=max(maxt[pos*2],maxt[pos*2+1]);
}
int qrymax(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
        return maxt[pos];
    int m=(tl+tr)/2;
    if(r<=m)
        return qrymax(tl,m,l,r,pos*2);
    if(l>m)
        return qrymax(m+1,tr,l,r,pos*2+1);
    return max(qrymax(tl,m,l,m,pos*2),qrymax(m+1,tr,m+1,r,pos*2+1));
}

int maxi[N],mini[N];
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("dynasties.in","r",stdin);
    //freopen("dynasties.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<N*4;++i)
        maxt[i]=-1;
    for(int i=0;i<n;++i)
    {
        int j=qrymax(0,N,a[i]+1,N,1);
        ubdmax(0,N,a[i],i,1);
        maxi[i]=j+1;
    }
    for(int i=0;i<N*4;++i)
        maxt[i]=-1;
    for(int i=0;i<n;++i)
    {
        int j=qrymax(0,N,0,a[i]-1,1);
        ubdmax(0,N,a[i],i,1);
        mini[i]=j+1;
    }
    minu.resize(n*4+10);
    maxu.resize(n*4+10);
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        ubd(maxu,0,n,maxi[i],i,a[i],1);
        ubd(minu,0,n,mini[i],i,a[i],1);
        ans+=(maxu[1].sum-minu[1].sum);
    }
    cout<<ans<<endl;
    return 0;
}