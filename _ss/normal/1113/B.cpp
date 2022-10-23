#include <iostream>

using namespace std;
const int maxn=int(5e4)+1;
int a[maxn],n,min1[maxn],min2[maxn],m3;
int main()
{
    cin>>n;
    int s=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s=s+a[i];
        min1[i]=a[i];
        min2[i]=a[i];
    }
    m3=s;
    int t;
    for (int i=2;i<=n;i++) min1[i]=min(min1[i],min1[i-1]);
    for (int i=n-1;i>=1;i--) min2[i]=min(min2[i],min2[i+1]);
    for (int i=2;i<=a[1];i++)
        if (a[1]%i==0) m3=min(m3,s-a[1]+a[1]/i-min2[2]+min2[2]*i);
    for (int i=2;i<=a[n];i++)
        if (a[n]%i==0) m3=min(m3,s-a[n]+a[n]/i-min1[n-1]+min1[n-1]*i);
    for (int i=2;i<=n-1;i++)
    {
        t=min(min1[i-1],min2[i+1]);
        for (int j=2;j<=a[i];j++)
            if (a[i]%j==0) m3=min(m3,s-a[i]+a[i]/j-t+t*j);
    }
    cout<<m3;
    return 0;
}