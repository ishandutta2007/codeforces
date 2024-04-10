#include <stdio.h>

int arr[300];
int mem[301][301];
char can[300][301];
bool vit[301];
int n;

void f(int x,int p)
{
    if(mem[p][x])
        return;
    int i;
    mem[p][x]=1;
    for(i=0;i<n;i++)
        if(can[p][i]=='1'||can[i][p]=='1')
            f(x,i);
}

int main()
{
    int t,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
        scanf("%s",can[i]);
    for(i=0;i<n;i++)
        f(arr[i],i);
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(!vit[j]&&mem[i][j])
            {
                vit[j]=1;
                printf("%d ",j);
                break;
            }
        }
    }
}