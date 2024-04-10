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
        for(int i=1;i<=n-1;i++)
        {
            if(k>i) k-=i;
            else
            {
                for(int j=0;j<n-i-1;j++) printf("a");
                printf("b");
                for(int j=0;j<i-k;j++) printf("a");
                printf("b");
                for(int j=0;j<k-1;j++) printf("a");
                printf("\n");
                break;
            }
        }
    }
    return 0;
}