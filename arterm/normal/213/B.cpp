#include <iostream>

#define p 1000000007
#define long long long
#define M 200


using namespace std;

long c[M][M],d[M][M],a[M],n;

void pre(void){
    for (long i=0; i<M; ++i){
        c[0][i]=0;
        c[i][0]=1;
    }
    for (long i=1; i<M; ++i)
    for (long j=1; j<M; ++j)
    c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
}

void read(void){
    cin>>n;
    for (long i=0; i<10; ++i)
    cin>>a[i];
}

void doit(void){
    long s=0;
    for (long l=0; l<=n; ++l)
    if (l>=a[9])
    d[9][l]=1;
    else
    d[9][l]=0;
    for (long j=8; j>=0; --j)
    for (long l=0; l<=n; ++l){
        d[j][l]=0;
        if (j!=0)
        for (long t=a[j]; t<=l; ++t)
        d[j][l]=(d[j][l]+d[j+1][l-t]*c[l][t])%p;
        if (j==0)
        for (long t=a[j]; t<=l; ++t)
        d[j][l]=(d[j][l]+d[j+1][l-t]*c[l-1][t])%p;
    }
    for (long i=n; i>=0; --i)
    s=(s+d[0][i])%p;
    cout<<s;
}


int main()
{
    pre();
    read();
    doit();
    return 0;
}