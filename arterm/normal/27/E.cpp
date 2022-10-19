#include <iostream>

#define long long long
#define N 1024
#define M  22
#define INF 1001000000000000000LL

using namespace std;

long a[9]={2,3,5,7,11,13,17,19,23};
long n,d[N][M], p[M][3*M],u[N][M];

long mind(long a, long b){
    long ans=1;
    for (long i=2; i<=a && b>0; ++i)
    while(!(a%i) && b>0){
        a/=i;
        b--;
        ans*=i;
    }
    return ans;
}

void pre(void){
    for (long i=0; i<N; ++i)
    for (long j=0; j<M; ++j)
    u[i][j]=0;
    for (long i=0; i<9; ++i)
    p[i][0]=1;
    for (long i=0; i<9; ++i)
    for (long j=1; j<64; ++j)
    p[i][j]=min(p[i][j-1]*a[i],INF);
}

long get(long a, long b){
    if (u[a][b])
    return d[a][b];
    u[a][b]=1;
    if (b==0)
    if (a<64)
    return d[a][b]=p[0][a-1];
    else
    return d[a][b]=INF;
    long m=INF,t;
    for(long i=5; i>=0; --i){
        t=mind(a,i);
        if (t*t<=a && t<64 && p[b][t-1]<INF && p[b][t-1]*get(a/t,b-1)<INF && p[b][t-1]*get(a/t,b-1)>0 && p[b][t-1]>0)
        m=min(m,(p[b][t-1]*get(a/t,b-1)));
    }
    return d[a][b]=m;
}

int main()
{
    pre();
    cin>>n;
    cout<<get(n,8);
    return 0;
}