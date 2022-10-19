#include <bits/stdc++.h>
using namespace std;
int a[51], b[51]; int n, dem, i ,j;
int main()
{
    dem=0;
    cin >> n;
    for (i=0;i<=n-1;i++)
    {
        cin >> a[i];
    }
    for (i=0;i<=n-1;i++)
    {
        for (j=0;j<=i-1;j++)
         {
             if (a[j]==a[i])
             {
                 a[j]=0;
             }

         }

    }
    for (i=0;i<=n-1;i++)
    {
        if (a[i]>0)
        {
            dem++;
            b[dem]=a[i];

        }
    }
    cout << dem << endl;
    for (i=1;i<=dem;i++)
    {
        cout << b[i] << " ";
    }

    return 0;

}