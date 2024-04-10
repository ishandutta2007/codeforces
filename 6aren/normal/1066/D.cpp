#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[200005];
int main()
{
    int i,cnt,rest;
    cin >> n >> m >> k;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    cnt=1;
    i=n;
    rest=k;
    while (i>=1 && cnt<=m)
    {
        if (a[i]>rest)
        {
            rest=k;
            cnt++;
        }
        else
        {
            rest=rest-a[i];
            i--;
        }
    }
    cout << n-i;
}