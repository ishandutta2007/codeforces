#include <iostream>

using namespace std;

int main()
{
    int n,a[101],k=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=n;i++)
        if (a[i]==0 & a[i-1]==1 & a[i+1]==1)
        {
            a[i+1]=0;
            k++;
        }
    cout<<k;
    return 0;
}