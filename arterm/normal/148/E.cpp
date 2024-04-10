#include <iostream>

#define N 121
#define M 10100

using namespace std;

long n,m,a[N][N],k[N],b[N][N],p[M],g[M];

void read(void){
    cin>>n>>m;
    for (long i=0; i<n; ++i){
        cin>>k[i];
        for (long j=1; j<=k[i]; ++j){
            cin>>a[i][j];
            a[i][j]+=a[i][j-1];
        }
    }
}

void pre(void){
    for (long i=0; i<n; ++i)
    for (long j=0; j<=k[i]; ++j)
    for (long l=0; l<=j; ++l)
    b[i][j]=max(b[i][j],(a[i][k[i]]-a[i][k[i]-j+l]+a[i][l]));
}

void din(void){
    for (long i=0; i<=k[0]; ++i)
    p[i]=b[0][i];
    for (long i=1; i<n; ++i){
        for (long j=0; j<=m; ++j)
        for (long t=0; t<=j && t<=k[i]; ++t)
        g[j]=max(g[j],(p[j-t]+b[i][t]));

        for (long j=0; j<=m; ++j){
            p[j]=g[j];
            g[j]=0;
        }

    }
}

int main()
{
    read();
    pre();
    din();
    cout<<p[m];
    return 0;
}