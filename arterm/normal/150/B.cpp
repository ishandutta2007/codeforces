#include <iostream>

#define M 2222
#define pr 1000000007
#define long long long

using namespace std;

long p[M];

void ini(void){
    for (long i=0; i<M; ++i)
    p[i]=i;
}

long get(long x){
    if (p[x]==x)
    return x;
    return p[x]=get(p[x]);
}

void uni(long x, long y){
    x=get(x);
    y=get(y);
    p[x]=y;
}

long pow(long m, long a){
    long ans=1;
    for (long i=0; i<a; ++i){
        ans*=m;
        ans%=pr;
    }
    return ans;
}

int main()
{
    ini();
    long n,m,k,u=0;
    cin>>n>>m>>k;
    for (long i=0; i+k<=n; ++i)
    for (long l=i,r=i+k-1; l<r; ++l,--r)
    uni(l,r);

    for (long i=0; i<n; ++i)
    if (p[i]==i)
    u++;

    cout<<pow(m,u);

    return 0;
}