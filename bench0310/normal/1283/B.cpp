#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int a=n/k;
        printf("%d\n",a*k+min(n-a*k,k/2));
    }
    return 0;
}