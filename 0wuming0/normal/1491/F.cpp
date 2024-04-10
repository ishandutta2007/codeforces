#include"bits/stdc++.h"
using namespace std;
int ans[2005],nn;
int save;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s=0;
        int n;
        scanf("%d",&n);
        int now;
        nn=0;save=-1;
        for(int i=n;;i--)
        {
            printf("? %d 1\n",i-1);
            for(int j=1;j<i;j++)printf("%d%c",j," \n"[j==i-1]);
            printf("%d\n",i);
            fflush(stdout);
            scanf("%d",&now);
            if(now)
            {
                s=now;
                now=i;
                break;
            }
        }
        int a;
        for(int i=1;i<now-1;i++)
        {
            printf("? 1 1\n");
            printf("%d\n",i);
            printf("%d\n",now);
            fflush(stdout);
            scanf("%d",&a);
            s-=a;
            if(!a)
            {
                s-=a;
                ans[nn++]=i;
            }
        }
        if(!s)
        {
            ans[nn++]=now-1;
        }
        if(now!=n)
        {
            if(now==n-1)
            {
                printf("? 1 1\n");
                printf("%d\n",n);
                printf("%d\n",n-1);
                fflush(stdout);
                scanf("%d",&a);
                if(a)
                {
                    save=n;
                }
            }
            else
            {
                int x1,x2,x;
                bool flag=0;
                x1=now+1;x2=n;
                while(x1+1<x2)
                {
                    int x=(x1+x2)/2;
                    printf("? %d 1\n",x-x1+1);
                    for(int j=x1;j<=x;j++)printf("%d%c",j," \n"[j==x]);
                    printf("%d\n",now);
                    fflush(stdout);
                    scanf("%d",&a);
                    if(a)
                    {
                        x2=x;
                        flag=1;
                    }
                    else
                    {
                        x1=x+1;
                    }
                }
                if(x1==x2)
                {
                    printf("? 1 1\n");
                    printf("%d\n",x1);
                    printf("%d\n",now);
                    fflush(stdout);
                    scanf("%d",&a);
                    if(a)
                    {
                        save=x1;
                    }
                }
                else
                {
                    printf("? 1 1\n");
                    printf("%d\n",x1);
                    printf("%d\n",now);
                    fflush(stdout);
                    scanf("%d",&a);
                    if(a)
                    {
                        save=x1;
                    }
                    else if(flag==1)
                    {
                        save=x2;
                    }
                    else
                    {
                        printf("? 1 1\n");
                        printf("%d\n",x2);
                        printf("%d\n",now);
                        fflush(stdout);
                        scanf("%d",&a);
                        if(a)save=x2;
                    }
                }
            }
        }
        for(int i=now+1;i<=n;i++)
        {
            if(i!=save)
            {
                ans[nn++]=i;
            }
        }
        printf("! %d ",nn);
        for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
        fflush(stdout);
    }
    return 0;
}