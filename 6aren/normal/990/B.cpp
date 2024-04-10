#include <bits/stdc++.h>
using namespace std;

long long n,k,i,t,u; long long a[1000000];
int main()
{
    cin >> n >> k;
    for (i=1;i<=n;i++)
        {cin >> a[i];}

    sort(a+1, a+1+n);
    t=n;
    u=1;
    for (i=2;i<=n;i++)
        {
            if (a[i-1]==a[i]) { u++; }
            if (a[i-1]+k>=a[i] && a[i-1]!=a[i]) { t=t-u;}
            if (a[i-1]!=a[i]) u=1;

        }
    cout << t;
}