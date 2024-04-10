#include <iostream>

#define M 5050
#define N 1000100
#define long long long

using namespace std;

long n,m,p,l[N],a[M][M],x[M],y[M],h[M],f[M];

void pre(void){
    a[1][1]=1;
    for (long i=2; i<M; ++i)
    for (long j=2; j<=i; ++j)
    a[i][j]=a[i-1][j-1]+(j-1)*a[i-1][j],a[i][j]%=p;
}

void read(void){
    cin>>n>>m>>p;
    for (long i=0; i<n; ++i)
    cin>>l[i];
    h[0]=1;
    f[0]=1;
    for (long i=1; i<M; ++i)
    h[i]=(h[i-1]*(m-i+1))%p,f[i]=(f[i-1]*i)%p;
}

void kill(void){
    long s=0;
    for (long i=1; i<=l[0]; ++i)
    x[i]=(a[l[0]][i]*h[i])%p;

    for (long i=1; i<=l[0]; ++i)
    s+=x[i],s%=p;


    for (long i=1; i<n; ++i){
        for (long j=1; j<=l[i]; ++j){
            y[j]=h[j]*s-f[j]*x[j];
            y[j]%=p;
            y[j]*=a[l[i]][j];
            y[j]%=p;
        }
        s=0;
        for (long j=0; j<=l[i+1]; ++j)
        x[j]=0;
        for (long j=1; j<=l[i]; ++j)
        x[j]=y[j],s+=x[j],s%=p;

    }

    s%=p;
    if (s<0)
    s+=p;
    cout<<s<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    pre();
    kill();
    return 0;
}