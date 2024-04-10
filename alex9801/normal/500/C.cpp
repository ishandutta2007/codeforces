#include <stdio.h>

int wei[501];
int arr[1001];
int stk[500];
bool chk[501];

int main()
{
    int n,m,p=0,r=0,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&wei[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=m;i++)
    {
        if(!chk[arr[i]])
        {
            chk[arr[i]]=1;
            stk[p++]=arr[i];
        }
    }
    for(i=1;i<=m;i++)
    {
        for(p=0;;p++)
            if(stk[p]==arr[i])
                break;
        for(j=p-1;j>=0;j--)
        {
            r+=wei[stk[j]];
            stk[j+1]=stk[j];
        }
        stk[0]=arr[i];
    }
    printf("%d",r);
    return 0;
}