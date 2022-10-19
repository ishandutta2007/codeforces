#include <iostream>
#include <algorithm>

#define long long long
#define p 1000000007
#define M 100100

using namespace std;

long n,a[M],s[M],v[M],k;

void read(void){
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i];

    sort(a,a+n);

    for (long i=0; i<n; ++i)
    s[a[i]]++;

    for (long i=1; i<M; ++i)
    s[i]=s[i]+s[i-1];

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

long calc(long d){

    k=0;
    long i,t,ps=0,ans=1,ol;

    for (i=1; i*i<d; ++i)
    if (d%i==0)
    v[k++]=i;

    t=k-1;

    if (i*i==d)
    v[k++]=i;

    for (;t>=0;--t)
    v[k++]=(d/v[t]);

    for (i=0; v[i]!=d; ++i){
        ol=s[v[i+1]-1]-ps;
        ans*=bin(i+1,ol);
        ans%=p;
        ps=s[v[i+1]-1];
    }

    ol=n-ps;


    ans*=(bin(k,ol)-bin(k-1,ol));
    ans%=p;

    return ans;

}

int main()
{
    read();
    long ans=0;
    for (long i=1; i<M; ++i)
    ans=(ans+calc(i))%p;
    ans%=p;
    if (ans<0)
    ans+=p;
    cout<<ans<<endl;
    return 0;
}