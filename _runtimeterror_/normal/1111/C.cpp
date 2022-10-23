#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

const int N=100005;
int n,k;
long long A,B,a[N];

long long go_(int l,int r)
{
    long long val=upper_bound(a,a+k,r)-lower_bound(a,a+k,l);
    if(l==r)
        return (val?val*B:A);
    int m=(l+r)/2;
    if(val==0)
        return A;
    return min((r-l+1)*val*B,go_(l,m)+go_(m+1,r));
}

int main()
{
    scanf("%d %d %lld %lld",&n,&k,&A,&B);
    for(int i=0;i<k;++i)
        scanf("%lld",a+i);
    sort(a,a+k);
    printf("%lld",go_(1,(1<<n)));
}