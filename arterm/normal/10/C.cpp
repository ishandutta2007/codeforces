#include <iostream>

#define M 13
#define long long long

using namespace std;


long n,a[M],d[M][M],s=0;

int main()
{
    cin>>n;

    for (long i=1; i<9; ++i)
    a[i]=(n-i+9)/9;

    a[0]=n/9;

    for (long i=0; i<9; ++i)
    for (long j=0; j<9; ++j)
    s=s+a[i]*a[j]*a[(i*j)%9];


    for (long i=1; i<=n; ++i)
    s=s-(n/i);
    cout<<s;
    return 0;
}