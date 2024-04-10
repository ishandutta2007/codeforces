#include <iostream>

using namespace std;
const int maxn=int(1e5)+1;
int n,a[maxn],m=0;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        m=max(m,a[i]);
    }
    int d=0,l=0;
    for (int i=1;i<=n;i++)
        if (a[i]==m) l++; else
        {
            d=max(d,l);
            l=0;
        }
    d=max(d,l);
    cout<<d;
    return 0;
}