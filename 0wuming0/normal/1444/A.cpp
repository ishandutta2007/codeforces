#include"bits/stdc++.h"
using namespace std;
int prime[40005];
int p[40005],nn;
int main()
{
    for(int i=2;i<40005;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;i*j<40005;j++)prime[i*j]=j;
            p[nn++]=i;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        long long a;
        int b;
        cin>>a>>b;
        int ad=b;
        for(int i=0;i<nn;i++)if(ad%p[i]==0)ad/=p[i--];
        long long ans=1;
        p[nn++]=ad;
        for(int i=0;i<nn;i++)if(b%p[i]==0&&p[i]!=1)
        {
            long long now=a;
            while(1)
            {
                if(now%b)ans=max(now,ans);
                if(now%p[i])break;
                now/=p[i];
            }
        }
        nn--;
        cout<<ans<<endl;
    }
    return 0;
}