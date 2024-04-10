#include <stdio.h>

int main()
{
    int m,s,i;
    scanf("%d%d",&m,&s);
    if(s==0&&m==1)
    {
        printf("0 0");
        return 0;
    }
    if(s==0||m*9<s)
    {
        printf("-1 -1");
        return 0;
    }
    if((s-1)/9+1==m)
    {
        if(s%9)
            printf("%d",s%9);
        for(i=0;i<s/9;i++)
            printf("9");
        printf(" ");
        for(i=0;i<s/9;i++)
            printf("9");
        if(s%9)
            printf("%d",s%9);
        return 0;
    }
    printf("1");
    for(i=0;i<m-(s-1)/9-2;i++)
        printf("0");
    if(s%9)
    {
        printf("%d",s%9-1);
        for(i=0;i<s/9;i++)
            printf("9");
    }
    else
    {
        printf("8");
        for(i=0;i<s/9-1;i++)
            printf("9");
    }
    printf(" ");
    for(i=0;i<s/9;i++)
        printf("9");
    if(s%9)
        printf("%d",s%9);
    for(i=0;i<m-(s-1)/9-1;i++)
        printf("0");
    return 0;
}