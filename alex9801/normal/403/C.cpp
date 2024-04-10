#include <stdio.h>
#include <string.h>

bool chk[2000];
int arr[2000][2000];
int n;

void f1(int x)
{
    int i;
    chk[x]=1;
    for(i=0;i<n;i++)
        if(!chk[i]&&arr[x][i])
            f1(i);
}

void f2(int x)
{
    int i;
    chk[x]=1;
    for(i=0;i<n;i++)
        if(!chk[i]&&arr[i][x])
            f2(i);
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    for(i=0;i<n;i++)
    {
        if(arr[i][i])
        {
            f1(i);
            for(j=0;j<n;j++)
            {
                if(!chk[j])
                {
                    printf("NO");
                    return 0;
                }
            }
            memset(chk,0,sizeof(chk));
            f2(i);
            for(j=0;j<n;j++)
            {
                if(!chk[j])
                {
                    printf("NO");
                    return 0;
                }
            }
            break;
        }
    }
    printf("YES");
    return 0;
}