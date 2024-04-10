#include"stdio.h"
int main()
{
    int a[100005],s[100005],x=0;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    for(i=0;i<n;i++)
    {
        x+=a[i];
        s[i]=x;
    }
    scanf("%d",&n);
    int l,r;
    while(n--)
    {
        scanf("%d%d",&l,&r);
        l--;r--;
        if(l==0)
        printf("%d\n",s[r]/10);
        else
        printf("%d\n",(s[r]-s[l-1])/10);
    }
    return 0;
}