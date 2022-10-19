#include"bits/stdc++.h"
using namespace std;
char s[300006];
int sum[300006];
void pr(int l,int r)
{
    int x1=l,x2=r+1;
    int op=1;
    if(sum[r]-sum[l-1]<0)op=-1;
    while(1)
    {
        int x=x1+x2>>1;
        if(sum[x-1]-sum[l-1]==sum[r]-sum[x])
        {
            printf("%d\n",x);
            return;
        }
        if((sum[r]-sum[x]-sum[x-1]+sum[l-1])*op>0)x1=x;
        else x2=x;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='+')sum[i]=2;
            if(i%2)sum[i]^=2;
            sum[i]--;
            sum[i]+=sum[i-1];
        }
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(sum[r]-sum[l-1]==0)printf("0\n");
            else if((sum[r]-sum[l-1])%2)
            {
                printf("1\n");
                pr(l,r);
            }
            else
            {
                printf("2\n");
                printf("%d ",l++);
                pr(l,r);
            }
        }
        for(int i=0;i<=n;i++)sum[i]=0;
    }
    return 0;
}