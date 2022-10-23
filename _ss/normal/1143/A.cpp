#include <iostream>

using namespace std;
const int N=2e5+1;

int a[N];

int main()
{
    int n,d0=0,d1=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==1) d1++; else d0++;
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]) d1--; else d0--;
        if (d1==0 || d0==0)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}