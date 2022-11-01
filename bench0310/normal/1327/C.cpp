#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    printf("%d\n",n+m-2+n*m-1);
    for(int i=0;i<n-1;i++) printf("U");
    for(int i=0;i<m-1;i++) printf("L");
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m-1;i++)
        {
            if(o&1) printf("L");
            else printf("R");
        }
        if(o==n-1) break;
        printf("D");
    }
    printf("\n");
    return 0;
}