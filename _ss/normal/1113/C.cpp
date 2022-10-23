#include <iostream>

using namespace std;
const int maxv=1048576,maxn=int(3e5)+1;
long long a[maxn],chan[maxv],le[maxv],n;
int main()
{
    cin>>n>>a[1];
    chan[0]=1;
    le[a[1]]++;
    for (long long i=2;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]^a[i-1];
        if (i%2==0) chan[a[i]]++; else le[a[i]]++;
    }
    long long d=0;
    for (long long i=0;i<maxv;i++) d=d+(chan[i]-1)*chan[i]/2+(le[i]-1)*le[i]/2;
    //for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<d;
    return 0;
}