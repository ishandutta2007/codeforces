#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> f;
long long n,a[200001],b[200001],sum=0;
void qsort(int l,int r)
{
    long long mid=a[(l+r)/2],i=l,j=r;
    while (i<=j)
    {
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsort(i,r);
    if (j>l) qsort(l,j);
}

int bs(long long x,int l,int r)
{
    long long mid=-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (a[mid]==x) return mid; else
        if (a[mid]<x) l=mid+1;
        if (a[mid]>x) r=mid-1;
    }
    if (a[mid]==x) return mid; else return -1;
}
int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
        b[i]=i;
    }
    qsort(1,n);
    for (int i=1;i<=n;i++)
    if ((sum-a[i])%2==0)
    {
        if (bs((sum-a[i])/2,1,i-1)>0 || bs((sum-a[i])/2,i+1,n)>0) f.push_back(b[i]);
    }
    cout<<f.size()<<endl;
    for (int i=0;i<f.size();i++) cout<<f[i]<<" ";
    return 0;
}