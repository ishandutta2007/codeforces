#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const int maxn=100011;
long long a[maxn],n,k,t1,t2;

int bs(int x)
{
    int l=0,r=k,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (a[mid]<x && a[mid+1]>=x) return mid+1;
        if (a[mid]<x) l=mid+1;
        if (a[mid]>=x) r=mid-1;
    }
    return mid;
}

int bs2(int x)
{
    int l=1,r=k+1,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (a[mid]>x && a[mid-1]<=x) return mid-1;
        if (a[mid]<=x) l=mid+1;
        if (a[mid]>x) r=mid-1;
    }
    return mid-1;
}

long long vl(long long l, long long r)
{
    long long sl=bs2(r)-bs(l)+1;
    if (sl==0) return t1;
    if (l==r) return  t2*sl*(r-l+1);
    long long t=vl(l,(l+r)/2)+vl((l+r)/2+1,r);
    if (t<t2*sl*(r-l+1)) return t; else return t2*sl*(r-l+1);
}
int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    cin>>n>>k>>t1>>t2;
    for (int i=1;i<=k;i++) cin>>a[i];
    sort(a+1,a+k+1);
    int r=1;
    for (int i=1;i<=n;i++) r=r*2;
    a[0]=0;
    a[k+1]=r+1;
    //for (int i=1;i<=8;i++) cout<<bs(i)<<" "<<bs2(i)<<endl;
    //cout<<k<<endl;
    cout<<vl(1,r);
    return 0;
}