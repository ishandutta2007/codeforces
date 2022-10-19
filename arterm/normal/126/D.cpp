#include <iostream>

#define long long long
#define F 90
#define INF 1000111000000000000LL

using namespace std;

long f[F],p[F],n;
bool u[F];

void pre(void){
    f[0]=1;
    f[1]=1;
    for (long i=2; i<F; ++i)
    f[i]=f[i-1]+f[i-2];
    /*for (long i=2; i<F; ++i)
    if (f[i]>INF)
    cout<<i<<" ";*/
}

long del(long k){
    while (!u[k+1] && u[k] && k>=2)
    k-=2;
    if (u[k+1])
    return 0;
    if (u[k])
    return 0;
    return p[k];
}

void test(void){
    long d=0,l=F;
    cin>>n;
    for (long i=0; i<F; ++i){
        p[i]=0;
        u[i]=0;
    }
    for (long i=F-1; i>0; --i)
    if (n>=f[i]){
        u[i]=1;
        n-=f[i];
        d=max(i,d);
        l=min(i,l);
    }
    u[0]=1;
    p[0]=1;
    p[1]=1;
    p[2]=1;
    for (long j=3; j<=d; ++j){
        if (!u[j-1] && !u[j-2])
        if (l<j)
        p[j]=p[j-2]+p[l];
        else
        p[j]=p[j-2]+1;

        if (!u[j-1] && u[j-2])
        if (!u[j-3] && j>4)
        p[j]=p[j-2]+del(j-2);
        else
        p[j]=p[j-2];

        if (u[j-1])
        p[j]=p[j-1];

        if (u[j])
        l=j;
    }
    cout<<p[d]<<"\n";
}


int main()
{
    long t;
    pre();
    cin>>t;
    for (long i=0; i<t; ++i)
    test();
    return 0;
}