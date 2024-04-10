#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,a[101];
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int m=int(10e9),t;
    for (int i=1;i<=n;i++)
    {
        t=0;
        for (int j=1;j<=n;j++) t=t+abs(i-j)*a[j]+a[j]*(j-1)+a[j]*(i-1)+a[j]*(j-1)+a[j]*(i-1)+abs(i-j)*a[j];
        m=min(t,m);
    }
    cout<<m;
    return 0;
}