#include <fstream>
#include <string>
#include <algorithm>

#define M 2000

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

int main()
{
    long n,f[M],t,a=1;
    cin>>n;
    f[2]=1;
    for (long i=3; i<=n; ++i)
    f[i]=1+f[(i+1)/2];
    cout<<f[n]<<"\n";
    for (long i=1; i<=f[n]; ++i,a<<=1){
        //cout<<i<<" ";
        t=0;
        for (long j=1; j<=n; ++j)
        if (j&a)
        ++t;
        cout<<t<<" ";
        for (long j=1; j<=n; ++j)
        if (j&a)
        cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}