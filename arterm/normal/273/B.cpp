#include <iostream>
#include <algorithm>

#define M 100100
#define T 200200
#define long long long

using namespace std;

long n,a[T],b[T],x[T],m,f[T],e[T];

void read(void){
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i],x[i]=a[i];
    for (long i=0; i<n; ++i)
    cin>>b[i],x[i+n]=b[i];

    cin>>m;

    sort(x,x+(2*n));
}

long odd(long x){
    while ((x&1)==0)
    x>>=1;
    return x;
}

long even(long x){
    long a=0;
    while ((x&1)==0)
    a++,x>>=1;
    return a;
}

void kill(void){
    f[0]=1;
    for (long i=1; i<T; ++i){
        f[i]=f[i-1]*odd(i);
        f[i]%=m;
        e[i]=e[i-1]+even(i);
    }
    long p=0,ans=1,s=0;

    for (long i=0; i<n; ++i)
    if (a[i]==b[i])
    ++p;

    n*=2;

    for (long i=0,j; i<n;){
        j=i;
        while (j<n && x[j]==x[i])
        ++j;

        ans*=f[j-i];
        ans%=m;
        s+=e[j-i];

        i=j;
    }

    s-=p;

    for (long i=0; i<s; ++i)
    ans*=2,ans%=m;

    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    kill();
    return 0;
}