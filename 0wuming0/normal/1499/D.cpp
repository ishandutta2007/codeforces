#include"bits/stdc++.h"
using namespace std;
int prime[20000007];
int pp[20000007],nn;
int ans[20000007];/*
int getsolve(int k)
{if(k%1000000==0)cout<<k<<endl;
    map<int,int>mp;
    while(prime[k]!=0)
    {
        //mp[prime[k]]=1;
        k/=prime[k];
    }
    //if(k>1)mp[k]=1;
    return mp.size();
}*/
long long solve(int k)
{
    return ((1ll)<<ans[k]);
}
int main()
{
    for(int i=2;i<20000007;i++)
    {
        if(prime[i]==0)
        {
            pp[nn++]=i;
        }
        for(int j=0;j<nn;j++)
        {
            if(i*pp[j]>20000007)break;
            prime[i*pp[j]]=pp[j];
        }
    }
    ans[1]=0;
    for(int i=2;i<20000007;i++)
    {
        if(prime[i]==0)ans[i]=1;
        else
        {
            ans[i]=ans[i/prime[i]];
            if(i/prime[i]%prime[i])ans[i]++;//cout<<i<<" "<<ans[i]<<endl;
        }
    }
    //for(int i=2;i<10000007;i++)if(prime[i]!=0&&prime[prime[i]]!=0)return 1;
    //for(int i=0;i<100;i++)cout<<pp[i]<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        long long c,d,x;
        cin>>c>>d>>x;
        long long ans=0;
        for(int i=1;i*i<=x;i++)if(x%i==0)
        {//cout<<"!!"<<i<<endl;
            int a=i;
            int b=x/i;
            {
                int q=x/a+d;//cout<<t<<" "<<a<<" "<<d<<" "<<q<<endl;
                if(q%c==0)
                {//cout<<"<<<"<<q/c<<" "<<a<<endl;
                    ans+=solve(q/c);
                }
            }
            if(b==a)continue;
            a=b;
            {
                int q=x/a+d;
                if(q%c==0)
                {//cout<<"<<<"<<q/c<<" "<<a<<endl;
                    ans+=solve(q/c);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}