#include <iostream>

#define long long long
#define M 100100

using namespace std;

long n,a[M],m,d=0;

void read(void){
    cin>>n;
    for (long i=1; i<=n; ++i)
    cin>>a[i];
}

void kill(void){
    cin>>m;
    for (long w,h,i=0;i<m; ++i){
        cin>>w>>h;
        long p=max(d,a[w]);
        cout<<p<<"\n";
        d=p+h;
    }
}

int main()
{
    read();
    kill();
    return 0;
}