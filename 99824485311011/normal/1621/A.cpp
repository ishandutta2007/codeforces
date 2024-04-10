#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if((n+1)/2<k)puts("-1");
        else
        {
            for(int i=0;i<n;i++)
            {
                if(!(i&1)&&i<2*k)
                {
                    for(int j=0;j<i;j++)putchar('.');
                    putchar('R');
                    for(int j=i+1;j<n;j++)putchar('.');
                }
                else
                {
                    for(int j=0;j<n;j++)putchar('.');
                }
                putchar('\n');
            }
        }
    }
    return 0;
}