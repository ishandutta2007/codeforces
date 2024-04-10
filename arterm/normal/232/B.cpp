#include <iostream>

#define long long long
#define p 1000000007
#define N 103
#define S 10010

using namespace std;

long n,m,k,d[N][S],c[N][N],pow[3][N];

long power(long x,long a){
    long b=1;
    while(a){
        if(a&1)
        b*=x;
        b%=p;
        x*=x;
        x%=p;
        a>>=1;
    }
    return b;
}

void pre(void){
    for (long i=0; i<N; ++i)
    c[i][0]=1;
    for (long i=1; i<N; ++i)
    for (long j=1; j<=i; ++j)
    c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;

    for (long j=0,d=m/n; j<=n; ++j){
        pow[0][j]=power(c[n][j],d);
        pow[1][j]=power(c[n][j],d+1);
    }
}

void din(void){
    long mod=m%n;
    for (long i=0; i<=n; ++i)
    if (1<=mod)
    d[1][i]=pow[1][i];
    else
    d[1][i]=pow[0][i];

    for (long i=2; i<=n; ++i)
    for (long s=k; s>=0; --s)
    for (long j=0; j<=n && j<=s; ++j)
    if (i<=mod)
    d[i][s]=(d[i][s]+d[i-1][s-j]*pow[1][j])%p;
    else
    d[i][s]=(d[i][s]+d[i-1][s-j]*pow[0][j])%p;

}

int main()
{
    cin>>n>>m>>k;
    pre();
    din();
    cout<<d[n][k]<<"\n";
    return 0;
}