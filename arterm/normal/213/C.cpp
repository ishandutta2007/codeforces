#include <iostream>

#define M 302
#define INF 1000000000

using namespace std;

long n, t[M][M], d[M][M],p[M][M];

void read(void){
    cin>>n;
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=n; ++j)
    cin>>t[i][j];
}

long work(void){
    long o=1;
    for (long i=0; i<=n; ++i)
    for (long j=0; j<=n; ++j){
        p[i][j]=-INF;
        d[i][j]=-INF;
    }


    p[1][1]=t[1][1];
    for (long s=3; s<=2*n; ++s){
        for (long a=max(o,(s-n)); a<=n && a<s && s-a<=n; ++a)
        for (long b=max(o,(s-n)); b<=n && b<s && s-b<=n; ++b){
            d[a][b]=max(d[a][b],p[a-1][b]);
            d[a][b]=max(d[a][b],p[a][b-1]);
            d[a][b]=max(d[a][b],p[a][b]);
            d[a][b]=max(d[a][b],p[a-1][b-1]);
            if (a==b)
            d[a][b]+=t[a][s-a];
            else
            d[a][b]+=(t[a][s-a]+t[b][s-b]);
        }
        for (long i=0; i<=n; ++i)
        for (long j=0; j<=n; ++j){
            p[i][j]=d[i][j];
            d[i][j]=-INF;
        }
    }
    return p[n][n];
}


int main()
{
    long s;
    read();
    cout<<work();
    return 0;
}