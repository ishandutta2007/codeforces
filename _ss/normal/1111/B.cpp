#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn=100001;
double a[maxn],k,m,s=0,tb,d=0,kq=0;
long long n;

int main()
{
    cin>>n>>k>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    m=m-n;
    sort(a+1,a+n+1);
    for (int i=n;i>=1;i--)
    {
        d=d+1;
        s=s+a[i];
        if (m+d>=0)
        {
            tb=s/d;
            if ((m+d)/d>k) tb=tb+k; else tb=tb+(m+d)/d;
            if (tb>kq) kq=tb;
        }
    }
    printf("%0.9f",kq);
    return 0;
}