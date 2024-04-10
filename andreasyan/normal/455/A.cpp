#include <iostream>
using namespace std;

long long a[100002],b[100002],c[100002],n,m,k,maxu;
int main()
{
    long long i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>m)
			m=a[i];
        b[a[i]]++;
    }
    c[1]=b[1];
    for(i=2;i<=m;i++)
    {
        c[i]+=c[i-2];
        if(c[i-1]>b[i]*i+c[i])
            c[i]=c[i-1];
        else
            c[i]+=b[i]*i;
    }
    cout<<c[m]<<endl;
    return 0;
}