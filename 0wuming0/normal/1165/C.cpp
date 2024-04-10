#include"stdio.h"
#include"string.h"
int main()
{
    int n,i,m=0;
    char c,s[200005],ans[200005];
    scanf("%d",&n);
    scanf("%s",s);
    for(i=0;i<n;i++)
    {
        c=s[i];
        for(i=i+1;i<n;i++)
            if(s[i]!=c)
            {
                ans[m]=c;
                ans[m+1]=s[i];
                m+=2;
                break;
            }
    }
    ans[m]=0;
    printf("%d\n",n-m);
    printf("%s\n",ans);
    return 0;
}