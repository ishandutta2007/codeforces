#include <iostream>
#include <algorithm>

#define long long long
#define f first
#define s second
#define M 100100

using namespace std;

long n,p=0,b[M];

void read(void){
    cin>>n;
    long k,a;
    b[0]=1;
    for (long i=1; i<=20; ++i)
    b[i]=4*b[i-1];

    for (long i=0; i<n; ++i){
        cin>>k>>a;
        if (k>=p)
        p=k+1;

        if (p-k<=20)
        while ( b[p-k]<a )
        ++p;

    }

    cout<<p<<"\n";
}


int main()
{
    read();
    return 0;
}