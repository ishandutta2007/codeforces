#include <iostream>
#include <algorithm>

#define M 100100

using namespace std;

long n,x,a[M],b[M];

void read(void){
    cin>>n>>x;
    for (long i=0; i<n; ++i)
    cin>>a[i];
    for (long i=0; i<n; ++i)
    cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
}

void greeed(void){
    long t=0;
    for (long i=n-1,j=0; i>=0 && j<n; --i){
        while (a[i]+b[j]<x && j+1<n)
        ++j;
        if (a[i]+b[j]>=x){
            ++t;
            ++j;
        }
    }
    cout<<1<<" "<<t;
}

int main()
{
    read();
    greeed();
    return 0;
}