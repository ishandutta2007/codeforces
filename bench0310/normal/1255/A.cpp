#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int n=max(a-b,b-a);
        int res=0;
        for(int i:{5,2,1})
        {
            res+=(n/i);
            n%=i;
        }
        printf("%d\n",res);
    }
    return 0;
}