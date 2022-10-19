#include <iostream>
#include <algorithm>

#define M 100100
#define long long long

using namespace std;

long q=M,m,n,a[M];

void read(void){
    cin>>m;
    for (long i=0,x; i<m; ++i){
        cin>>x;
        q=min(q,x);
    }
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i];
    sort(a,a+n);
}

void kill(void){
    long s=0;
    for (long i=n-1; i>=0;i-=(q+2))
    for (long j=0; j<q && i-j>=0; ++j)
    s+=a[i-j];
    cout<<s<<"\n";
}

int main()
{
    read();
    kill();
    return 0;
}