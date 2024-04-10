#include <iostream>

using namespace std;
int n,x;
int main()
{
    cin>>n;
    int d1=0,d2=0;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x>0) d1++;
        if (x<0) d2++;
    }
    n=(n+1)/2;
    if (d1<n && d2<n) cout<<0;
    else if (d1>=n) cout<<1;
    else cout<<-1;
    return 0;
}