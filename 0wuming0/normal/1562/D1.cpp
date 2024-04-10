#include"bits/stdc++.h"
using namespace std;
char s[300006];
int sum[300006];
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
            else if((sum[r]-sum[l-1])%2)printf("1\n");
            else printf("2\n");
        }
        for(int i=0;i<=n;i++)sum[i]=0;
    }
    return 0;
}