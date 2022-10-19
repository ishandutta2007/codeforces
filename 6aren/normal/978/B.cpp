#include <bits/stdc++.h>
using namespace std;
string xau; int n, i, dem; int a[101];
int main()
{
    cin >> n;
    cin >> xau;
    for (i=0;i<=100;i++) a[i]=0;
    for (i=0;i<=n-1;i++)
    {
        if (i==0 && xau[0]=='x') a[i]=1;
            else
        {
            if (xau[i]=='x')
            {
                a[i]=a[i-1]+1;
                a[i-1]=0;
            }
        }

    }
    for (i=0;i<=n-1;i++)
    {
        if (a[i]>=3) dem=dem+a[i]-2;
    }
    cout << dem;
}