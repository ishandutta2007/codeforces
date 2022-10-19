#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
long long k;
long long a[N];

long long gcd(long long x,long long y)
{
    if(x==0)
        return y;
    return gcd(y%x,x);
}

long long t[N*4];

void bil(int tl,int tr,int pos)
{
    if(tl==tr)
    {
        t[pos]=gcd(a[tl],k);
        return;
    }
    int m=(tl+tr)/2;
    bil(tl,m,pos*2);
    bil(m+1,tr,pos*2+1);
    t[pos]=gcd(k,t[pos*2]*t[pos*2+1]);
}

long long qry(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
        return t[pos];
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(tl,m,l,r,pos*2);
    if(l>m)
        return qry(m+1,tr,l,r,pos*2+1);
    return gcd(k,qry(tl,m,l,m,pos*2)*qry(m+1,tr,m+1,r,pos*2+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    bil(1,n,1);
    int l=1,r=0;
    long long ans=0;
    while(1)
    {
        if(l==n+1 || r==n+1)
            break;
        if(l>r || qry(1,n,l,r,1)!=k)
        {
            ++r;
        }
        else
        {
            ans+=(n-r+1);
            ++l;
        }
    }
    cout<<ans<<endl;
    return 0;
}