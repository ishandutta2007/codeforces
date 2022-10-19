#include <iostream>
#include <algorithm>

#define long long long
#define M 100100

using namespace std;

long n,a[M];

long gcd(long x, long y){
    while (x){
        y%=x;
        swap(x,y);
    }
    return x+y;
}

void read(void){
    cin>>n;
    for (int i=0; i<n; ++i)
    cin>>a[i];
    sort(a,a+n);
}

void kill(void){
    long ans=0;
    for (int i=0; i+1<n; ++i)
    ans=ans+2*(a[i+1]-a[i])*(i+1)*(n-1-i);
    for (int i=0; i<n; ++i)
    ans+=a[i];
    long d=gcd(n,ans);
    cout<<ans/d<<" "<<n/d<<"\n";
}

int main(){
    read();
    kill();
    return 0;
}