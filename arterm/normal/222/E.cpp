#include <iostream>

#define long long long
#define M 60
#define p 1000000007

using namespace std;

long n,m,k,a[M][M],b[M][M],h[M][M];

long num(char ch){
    if ('a'<=ch && ch<='z')
    return ch-'a'+1;
    return ch-'A'+27;
}

void read(void){

    char l,r;

    cin>>n>>m>>k;

    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j){
        if (i==j)
        h[i][j]=1;
        a[i][j]=1;
    }


    for (long i=0; i<k; ++i){
        cin>>r>>l;
        a[num(l)][num(r)]=0;
    }
}

void sqr(void){
    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j)
    b[i][j]=0;

    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j)
    for (long k=1; k<=m; ++k){
        b[i][j]+=(a[i][k]*a[k][j]);
        b[i][j]%=p;
    }

    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j)
    a[i][j]=b[i][j];
}

void mul(void){
    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j)
    b[i][j]=0;

    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j)
    for (long k=1; k<=m; ++k){
        b[i][j]+=(h[i][k]*a[k][j]);
        b[i][j]%=p;
    }

    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j)
    h[i][j]=b[i][j];
}

void bin(void){
    long t=1;
    while (t<=n){
        if (t&n)
        mul();
        sqr();
        t<<=1;
    }
}

int main()
{
    long ans=0;
    read();
    n--;
    bin();
    for (long i=1; i<=m; ++i)
    for (long j=1; j<=m; ++j){
        ans+=h[i][j];
        ans%=p;
    }
    cout<<ans;
    return 0;
}