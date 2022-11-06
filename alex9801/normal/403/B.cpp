#include <stdio.h>

bool chk[40000];
int pri[4000];
int arr[5000];
int bad[5000];
int gcd[5000];

int f(int a,int b)
{
    return a?f(b%a,a):b;
}

int main()
{
    int n,m,t,c,p=0,i,j;
    for(i=2;i<40000;i++)
    {
        if(!chk[i])
        {
            pri[p++]=i;
            for(j=i*i;j<40000;j+=i)
                chk[j]=1;
        }
    }
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<m;i++)
        scanf("%d",&bad[i]);
    gcd[0]=arr[0];
    for(i=1;i<n;i++)
        gcd[i]=f(gcd[i-1],arr[i]);
    for(i=n-1;i>=0;i--)
    {
        t=gcd[i];
        c=0;
        for(j=0;j<m;j++)
        {
            if(t==1)
                break;
            if(t%bad[j]==0)
            {
                c--;
                t/=bad[j];
                j--;
            }
        }
        for(j=0;j<p;j++)
        {
            if(t==1)
                break;
            if(t%pri[j]==0)
            {
                c++;
                t/=pri[j];
                j--;
            }
        }
        if(t>1)
            c++;
        if(c<0)
        {
            for(j=0;j<=i;j++)
            {
                arr[j]/=gcd[i];
                gcd[j]/=gcd[i];
            }
        }
    }
    c=0;
    for(i=0;i<n;i++)
    {
        t=arr[i];
        for(j=0;j<m;j++)
        {
            if(t==1)
                break;
            if(t%bad[j]==0)
            {
                c--;
                t/=bad[j];
                j--;
            }
        }
        for(j=0;j<p;j++)
        {
            if(t==1)
                break;
            if(t%pri[j]==0)
            {
                c++;
                t/=pri[j];
                j--;
            }
        }
        if(t>1)
            c++;
    }
    printf("%d",c);
    return 0;
}