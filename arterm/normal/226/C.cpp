#include <iostream>

#define long long long

using namespace std;

long m=100000000LL,l=1,r=1000000000LL,k=2,d;
long a[10][10],b[10][10],c[10][10];

void squ(void){
    for (long i=1; i<=2; ++i)
    for (long j=1; j<=2; ++j)
    b[i][j]=0;

    for (long i=1; i<=2; ++i)
    for (long j=1; j<=2; ++j)
    for (long k=1; k<=2; ++k){
        b[i][j]+=(a[i][k]*a[k][j]);
        b[i][j]%=m;
    }
    for (long i=1; i<=2; ++i)
    for (long j=1; j<=2; ++j)
    a[i][j]=b[i][j];
}

void mul(void){
    for (long i=1; i<=2; ++i)
    for (long j=1; j<=2; ++j)
    b[i][j]=0;

    for (long i=1; i<=2; ++i)
    for (long j=1; j<=2; ++j)
    for (long k=1; k<=2; ++k){
        b[i][j]+=(c[i][k]*a[k][j]);
        b[i][j]%=m;
    }
    for (long i=1; i<=2; ++i)
    for (long j=1; j<=2; ++j)
    c[i][j]=b[i][j];

}

long n_th(long d){
    c[1][1]=1;
    c[2][2]=1;
    a[1][1]=1;
    a[1][2]=1;
    a[2][1]=1;
    while (d>0){
        if (d%2==1)
        mul();
        squ();
        d/=2;
    }
    return c[1][1]%m;
}

bool good(long x){
    long f=(l+x-1)/x;
    f=f+k-1;
    return f*x<=r;
}

long bin(void){
    long z=(r-l)/(k-1);
    while ((r/z-k+1)*z<l)
    z--;
    return z;
}

long small(){
    long t=(r-l)/(k-1),z=1,le=1,re=r,m;
    while (re>le){
        m=(le+re)/2;
        if (r/m>t)
        le=m+1;
        else
        re=m;
    }
    z=m;
    while ((r/(r/z)-k+1)*(r/z)<l)
    ++z;
    return r/z;
}



int main()
{
    long y,f;
    cin>>m>>l>>r>>k;

    if (k>980)
    d=bin();
    else
    d=small();

    y=n_th(d-1);
    if (y<0)
    y+=m;
    cout<<y<<"\n";
    return 0;
}