#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000][1001];
    int row,col,i,j,k,cnt=0;
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
        scanf("%s",s[i]);
    for(i=1;i<row;i++)
        if(strcmp(s[i],s[i-1])<0)
        {
            for(j=0;j<col;j++)
                if(s[i][j]<s[i-1][j])
                    break;
            for(k=0;k<row;k++)
                s[k][j]='a';
            cnt++;
            i=0;
        }
    printf("%d\n",cnt);
    return 0;
}