#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        long long l,r;
        scanf("%I64d%I64d%I64d",&n,&l,&r);
        long long now=0;
        for(long long i=1;i<=n-1;i++)
        {
            long long x=(2*(n-i));
            if(l<=now+x)
            {
                for(long long j=1;j<=x;j++)
                {
                    if(now+j<l) continue;
                    if(now+j>r) break;
                    if(j&1) printf("%I64d ",i);
                    else printf("%I64d ",j/2+i);
                }
            }
            now+=x;
        }
        if(r==n*(n-1)+1) printf("1");
        printf("\n");
    }
    return 0;
}