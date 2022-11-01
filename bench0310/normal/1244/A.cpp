#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        bool found=0;
        for(int i=0;i<=k;i++)
        {
            if(i>=((a+c-1)/c)&&(k-i)>=((b+d-1)/d))
            {
                printf("%d %d\n",i,k-i);
                found=1;
                break;
            }
        }
        if(!found) printf("-1\n");
    }

    return 0;
}