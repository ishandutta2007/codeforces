#include <bits/stdc++.h>
using namespace std;
int n,a[2005],r,res;
int main()
{
    int i,j;
    cin >> n >> r;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    i=1;
    while (i<=n)
    {
        int mini=max(0,i-r+1);
        for (j=i+r-1;j>=mini;j--)
        {
            if (a[j]==1) {
                res++;
                break;
            }
            if (j==mini && a[j]==0)
            {
                cout << -1;
                return 0;
            }
        }
        //cout << 1;
        i=j+r;
    }
    cout << res;
}