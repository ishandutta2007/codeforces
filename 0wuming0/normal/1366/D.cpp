#include"bits/stdc++.h"
using namespace std;
int p[10000006];
int prime[10000006],nn;
int ans[500005][2];
int main()
{
    for(int i=2;i<10000006;i++)
    {
        if(p[i]==0)
        {
            prime[nn++]=i;
        }
        for(int j=0;j<nn;j++)
        {
            if(prime[j]*i>=10000006)break;
            p[prime[j]*i]=prime[j];
            if(i%prime[j]==0)break;
        }
    }//for(int i=2;i<10000006;i++)if(p[i])if(p[p[i]])return 1;
    nn=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {//cout<<i<<endl;
        int c;
        scanf("%d",&c);
        int pp=p[c];
        int now=1;
        if(c==1||pp==0)
        {
            ans[nn][0]=-1;
            ans[nn++][1]=-1;
            continue;
        }
        while(1)
        {
            if(c%pp==0)
            {
                now*=pp;
                c/=pp;
            }
            else break;
        }
        if(c==1)
        {
            ans[nn][0]=-1;
            ans[nn++][1]=-1;
        }
        else
        {
            ans[nn][0]=c;
            ans[nn++][1]=now;
        }
    }
    for(int i=0;i<nn;i++)printf("%d%c",ans[i][0]," \n"[i==nn-1]);
    for(int i=0;i<nn;i++)printf("%d%c",ans[i][1]," \n"[i==nn-1]);
    return 0;
}