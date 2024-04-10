#include <iostream>

using namespace std;

int main()
{
    int n,a[101],m=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int d=0;
    if (a[1]==1 && a[2]==2) d++;
    for (int i=2;i<=n-1;i++)
        if (a[i]-1==a[i-1] && a[i]+1==a[i+1]) d++; else
        {
            m=max(d,m);
            d=0;
        }
    if (a[n-1]==999 && a[n]==1000) d++;
    m=max(d,m);
    cout<<m;
    return 0;
}