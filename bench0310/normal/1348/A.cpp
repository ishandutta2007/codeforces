#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a=0,b=0;
        for(int i=1;i<=n/2-1;i++) a+=(1<<i);
        a+=(1<<n);
        for(int i=n/2;i<n;i++) b+=(1<<i);
        printf("%d\n",abs(a-b));
    }
    return 0;
}