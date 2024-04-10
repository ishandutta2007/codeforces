#include <iostream>

#define long long long
#define p 1000000009ll

using namespace std;

long n,m,k;

long bin(long x, long a){
    long y=1;
    while (a){
        if (a&1)
        y*=x,y%=p;
        x*=x,x%=p;
        a>>=1;
    }
    return y;
}

int main()
{
    cin>>n>>m>>k;
    
    long t=n/k,r=n%k,ans=0;
    
    long a=m-r-(k-1)*t;
    if (a<=0)
    a=0;
    
    
    ans=(bin(2,a+1)+p-2)%p;
    ans=(ans*k)%p;
    
    ans=(ans+m-k*a)%p;
    
    cout<<ans<<"\n";
    
    return 0;
}