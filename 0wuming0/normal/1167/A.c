#include"stdio.h"
#include"string.h"
void solve(char s[])
{
    int i,n=strlen(s);
    for(i=0;i<=n-11;i++)
    {
        if(s[i]=='8')
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
int main()
{
    int n;
    char s[105];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%*d%s",s);
        solve(s);
    }
    return 0;
}