#include"bits/stdc++.h"
using namespace std;
int p[1005],nn;
int main()
{
    for(int i=2;i<1005;i++)
    {
        int t=min((int)sqrt(i)+3,i-1);
        int j;
        for(j=2;j<=t;j++)
        {
            if(i%j==0)break;
        }
        if(j==t+1)p[nn++]=i;
    }
    //for(int i=0;i<nn;i++)cout<<p[i]<<endl;
    int a,b;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a<b)swap(a,b);
        for(int i=0;i<nn;i++)
        {
            if(b%p[i]==0)
            {
                int t1=0,t2=0;
                while(a%p[i]==0)a/=p[i],t1++;
                while(b%p[i]==0)b/=p[i],t2++;
                if(t1<t2)swap(t1,t2);
                if(t1>t2*2)
                {
                    printf("No\n");
                    goto ne;
                }
                if((t1+t2)%3)
                {
                    printf("No\n");
                    goto ne;
                }
            }
        }
        if(a%b==0&&a/b==b)
        {
            printf("Yes\n");
            continue;
        }
        if(a==b&&a==1)printf("Yes\n");
        else printf("No\n");
        ne:;
    }
    return 0;
}