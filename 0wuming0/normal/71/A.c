#include"stdio.h"
#include"string.h"
int main()
{
    int n,m;
    char s[101];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        m=strlen(s);
        if(m>10)printf("%c%d%c\n",s[0],m-2,s[m-1]);
        else printf("%s\n",s);
    }
    return 0;
}