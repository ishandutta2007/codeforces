#include <iostream>

#define M 20
#define T 1<<10+10

using namespace std;

//const double D=1e18,
const double eps=0.0000001;

double a[M][M], f[T];
long n,b[M];

void read(void){
    cin>>n;
    for (long i=0; i<n; ++i)
    for (long j=0; j<n; ++j)
    cin>>a[i][j];
}

void din(void){
    long t=(1<<n)-1;
    double s,k;
    f[t]=1;

    for(long i=0; i<n; ++i)
    b[i]=1<<i;

    for (; t>0; --t)
    for (long i=0; i<n; ++i)
    if (t&b[i]){
        k=0;
        s=0;
        for (long j=0; j<n; ++j)
        if (t&b[j]){
            s+=(a[j][i]);
            k+=1;
        }
        k=(k-1)*k/2;
        s*=f[t];
        if (k)
        s/=k;
        if(k)
        f[(t^b[i])]+=s;
    }

    cout.precision(6);

    for (long i=0; i<n; ++i)
    cout<<fixed<<f[b[i]]<<" ";
}

int main()
{
    read();
    din();
    return 0;
}