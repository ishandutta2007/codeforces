#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("W");
        for(int o=0;o<n;o++)
        {
            for(int i=(o==0);i<m;i++) printf("B");
            printf("\n");
        }
    }
    return 0;
}