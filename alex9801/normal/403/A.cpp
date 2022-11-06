#include <stdio.h>
#include <string.h>

int mem[50][50];

int main()
{
    int c,t,n,p,b,i,j;
    scanf("%d",&t);
    for(b=0;b<t;b++)
    {
        memset(mem,0,sizeof(mem));
        c=0;
        scanf("%d%d",&n,&p);
        for(i=1;i<5;i++)
        {
            for(j=i+1;j<=5;j++)
            {
                printf("%d %d\n",i,j);
                mem[i][j]=1;
            }
        }
        for(i=6;i<=n;i++)
        {
            printf("%d %d\n%d %d\n",i,i-1,i,i-2);
            mem[i-1][i]=1;
            mem[i-2][i]=1;
        }
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(!mem[i][j])
                {
                    if(c==p)
                        break;
                    c++;
                    printf("%d %d\n",i,j);
                }
            }
            if(c==p)
                break;
        }
    }
    return 0;
}