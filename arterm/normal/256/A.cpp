#include <iostream>
#include <algorithm>

#define M 4040

using namespace std;

long a[M],n,d[M][M],b[M];

int main()
{
    long x=0,y=0,ans=0;
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i],b[i]=a[i];

    sort(b,b+n);

    for (long i=0; i<n; ++i)
    a[i]=(long)(upper_bound(b,b+n,a[i])-b);

    for (long i=0; i<n; ++i)
    for (long j=0; j<i; ++j)
    d[i][a[j]]=max(d[i][a[j]],(d[j][a[i]]+1));

    for (long i=0; i<n; ++i)
    for (long j=0; j<M; ++j)
    ans=max(ans,d[i][j]);

    cout<<ans+1;


    return 0;
}