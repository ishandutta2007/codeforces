#include<cstdio>
typedef long long ll;
bool flag[11111111];
ll n;
int main()
{
    scanf("%lld",&n);
    ll i,ii;
    if(n==1)printf("1\n1\n");
    else if(n==2)printf("1\n1 1\n");
    else
    {
        n++;
        printf("2\n");
        for(i=2;i<n;i++)
        {
            printf("%d ",(int)flag[i]+1);
            if((!flag[i]))
                if(i*i<=n)
                    for(ii=i;ii*i<=n;ii++)
                        flag[ii*i]=1;
        }
        printf("%d\n",(int)flag[n]+1);
    }
}