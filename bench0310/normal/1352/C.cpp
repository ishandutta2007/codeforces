#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int x=(k/(n-1));
        printf("%d\n",x*n+k%(n-1)-((k%(n-1))==0));
    }
    return 0;
}