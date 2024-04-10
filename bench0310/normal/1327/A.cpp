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
        int i;
        for(i=1;;i+=2)
        {
            if(k==1||n<=0) break;
            n-=i;
            k--;
        }
        if(k==1&&n>0&&(n&1)&&n>=i) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}