#include <stdio.h>
#include <string.h>

char arr[100000][9];
char ori[100000][9];
int len[100000];

int main()
{
    bool u;
    int n,p,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",arr[i]);
    for(i=0;i<n;i++)
        len[i]=strlen(arr[i]);
    for(i=1;i<n;i++)
    {
        if(len[i-1]>len[i])
        {
            printf("NO");
            return 0;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<len[i];j++)
            ori[i][j]=arr[i][j];
    if(arr[0][0]=='?')
        arr[0][0]='1';
    for(i=1;i<len[0];i++)
        if(arr[0][i]=='?')
            arr[0][i]='0';
    for(i=1;i<n;i++)
    {
        if(len[i-1]<len[i])
        {
            if(arr[i][0]=='?')
                arr[i][0]='1';
            for(j=1;j<len[i];j++)
                if(arr[i][j]=='?')
                    arr[i][j]='0';
        }
        else
        {
            u=0;
            p=-1;
            for(j=0;j<len[i];j++)
            {
                if(arr[i][j]=='?')
                {
                    arr[i][j]=arr[i-1][j];
                    if(arr[i][j]!='9')
                        p=j;
                }
                else
                {
                    if(arr[i-1][j]>arr[i][j])
                    {
                        if(p==-1)
                        {
                            printf("NO");
                            return 0;
                        }
                        arr[i][p]++;
                        for(k=p+1;k<len[i];k++)
                            if(ori[i][k]=='?')
                                arr[i][k]='0';
                        u=1;
                        break;
                    }
                    if(arr[i-1][j]<arr[i][j])
                    {
                        for(k=j+1;k<len[i];k++)
                            if(ori[i][k]=='?')
                                arr[i][k]='0';
                        u=1;
                        break;
                    }
                }
            }
            if(!u)
            {
                if(p==-1)
                {
                    printf("NO");
                    return 0;
                }
                arr[i][p]++;
                for(k=p+1;k<len[i];k++)
                    if(ori[i][k]=='?')
                        arr[i][k]='0';
            }
        }
    }
    printf("YES\n");
    for(i=0;i<n;i++)
        printf("%s\n",arr[i]);
    return 0;
}