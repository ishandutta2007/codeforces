#include <iostream>

#define K 30
#define M 2222
#define mod 1000000007
#define long long long

using namespace std;

long p[K][M],n,k,a[M],b[M];

void pre(void){
    for (long i=0; i<=n; ++i)
    p[0][i]=1;



    for (long k=1; k<K; ++k)
    for (long j=0; j<n; ++j)
    for (long i=j; i<n; ++i)
    p[k][i]=(p[k][i]+p[k-1][j]*p[k-1][i-j])%mod;
}

void add(long t){
    for (long j=0; j<n; ++j)
    b[j]=0;

    for (long j=0; j<n; ++j)
    for (long i=j; i<n; ++i)
    b[i]=(b[i]+a[j]*p[t][i-j])%mod;
    for (long i=1; i<=n; ++i)
    a[i]=b[i];
}

int main()
{
    n=2012;
    pre();
    cin>>n>>k;
    for (long i=0; i<n; ++i)
    cin>>a[i];
    for (long j=1,t=0; j<=k; j<<=1,++t)
    if (k&j)
    add(t);

    for (long i=0; i<n; ++i)
    cout<<a[i]<<" ";


    return 0;
}