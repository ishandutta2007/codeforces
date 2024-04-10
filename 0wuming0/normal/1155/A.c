#include"stdio.h"
#include"string.h"
#define ll long long
int main()
{
    char s[300006];
    gets(s);
    scanf("%s",s);
    char *p=s;
    while(*(p+1))
    {
        p++;
        if(*p<*(p-1))
        {
            int a;
            a=p-s;
            printf("YES\n");
            printf("%d %d\n",a,a+1);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}