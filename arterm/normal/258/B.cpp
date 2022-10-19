#include <iostream>

#define M 20
#define p 1000000007
#define long long long

using namespace std;

long m,d[M][M],z[M][M],e[M][M][M],a[M],l=0,h[M],lu[]={0,0,0,0,1,0,0,1,0,0},ls[M],ans=0;

void prep(void){
    long t=m;
    while (t>0){
        a[l]=t%10;
        t/=10;
        l++;
    }
}

void din(void){
    d[1][0]=7;
    d[1][1]=2;
    z[1][0]=8;
    z[1][1]=2;
    z[0][0]=1;
    for (long i=2; i<M; ++i){
        for (long j=1; j<10; ++j)
        for (long k=0; k+1<M; ++k)
        if (j==4 || j==7)
        d[i][k+1]=(d[i][k+1]+z[i-1][k])%p;
        else
        d[i][k]=(d[i][k]+z[i-1][k])%p;
        for (long j=0; j<10; ++j)
        for (long k=0; k+1<M; ++k)
        if (j==4 || j==7)
        z[i][k+1]=(z[i][k+1]+z[i-1][k])%p;
        else
        z[i][k]=(z[i][k]+z[i-1][k])%p;
    }
}

void make(void){
    long s=0,len;

    for (long i=1; i<l; ++i)
    for (long k=0; k<M; ++k)
    h[k]=(h[k]+d[i][k])%p;

    for (long i=l-1; i>=0; --i){

        for (long j=1; j<a[i]; ++j)
        for (long k=0; k+1<M; ++k)
        h[k+lu[j]+s]=(h[k+lu[j]+s]+z[i][k])%p;

        if (i+1!=l && a[i]!=0)
        for (long k=0; k+1<M; ++k)
        h[k+s]=(h[k+s]+z[i][k]);

        s+=lu[a[i]];
    }
    h[s]=(h[s]+1)%p;
}

long bin(long x, long a){
    long b=1;
    while (a){
        if (a&1)
        b*=x,b%=p;
        x*=x,x%=p;
        a>>=1;
    }
    return b;
}

long cnk(long x, long y){
    long t=1;
    if (x<y)
    return 0;
    for (long i=0; i<y; ++i)
    t*=(x-i),t%=p;
    for (long i=1; i<=y; ++i)
    t*=bin(i,p-2),t%=p;
    return t;
}

void kill(void){
    for (long i=0; i<10; ++i)
    e[0][0][i]=cnk(h[0],i);

    for (long j=1; j<15; ++j)
    for (long i=0; i<10; ++i)
    for (long s=0; s<15; ++s)
    for (long k=0; k*j<=s && k<=i; ++k)
    e[j][s][i]=(e[j][s][i]+cnk(h[j],k)*e[j-1][s-k*j][i-k])%p;

    for (long i=0; i<15; ++i)
    ls[i]=e[13][i][6];

    for (long i=0; i<15; ++i)
    for (long j=i+1; j<15; ++j)
    ans=(ans+ls[i]*h[j])%p;

    for (long i=1; i<=6; ++i)
    ans=(ans*i)%p;

    cout<<ans<<endl;

}

int main()
{
    cin>>m;
    prep();
    din();
    make();
    kill();
    //for (long i=0; i<10; ++i)
    //cout<<i<<" -- "<<h[i]<<"\n";
    return 0;
}