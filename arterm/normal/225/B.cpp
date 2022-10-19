#include <iostream>

#define long long long


using namespace std;

long f[1000],k,s,a[1000];

int main()
{
    long i,t=0;
    cin>>s>>k;
    f[0]=0;
    f[1]=1;
    for (i=2; f[i-1]<s; ++i)
    for (long j=i-1; j>=0 && j>=i-k; --j)
    f[i]+=f[j];
    for (;i>0 && s>0;--i)
    if (f[i]<=s){
        s-=f[i];
        a[t++]=f[i];
    }
    cout<<t<<"\n";
    for (long i=0; i<t; ++i)
    cout<<a[i]<<" ";
    return 0;
}