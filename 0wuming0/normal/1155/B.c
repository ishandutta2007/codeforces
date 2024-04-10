#include"stdio.h"
#include"string.h"
#define ll long long
int main()
{
    int a,b;
    int n;
    scanf("%d",&n);
    b=(n-11)/2;
    a=n-11-b;
    char s[200000];
    scanf("%s",s);
    char *p=s;
    while(*p)
    {
        if(*p=='8')
        {
            b--;
        }
        else
        {
            a--;
        }
        if(a==-1)
        {
            printf("NO\n");
            return 0;
        }
        if(b==-1)
        {
            printf("YES\n");
            return 0;
        }
        p++;
    }
    return 0;
}