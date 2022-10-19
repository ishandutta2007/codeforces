#include"bits/stdc++.h"
using namespace std;
#define ll long long
int mod=1e9+7;
int a[100005];
int b[100005];
ll _2[100005];
int main()
{
    _2[0]=1;
    for(int i=1;i<=100000;i++)_2[i]=_2[i-1]*2%mod;
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int num=0;
    for(int i=2;i<=70;i++)
    {
        int j;
        for(j=2;j<i;j++)
        {
            if(i%j==0)break;
        }
        if(j==i)
        {
            for(int k=0;k<n;k++)
            {
                while(a[k]%i==0)
                {
                    a[k]/=i;
                    b[k]^=(1<<num);
                }
                //if(b%)
            }
            if(i>35)mp[1<<num]=0;
            num++;
            //cout<<i<<endl;
        }
    }
    //for(int i=0;i<n;i++)i--
    for(int i=0;i<n;i++)
    {
        if(b[i]>=2048)
        {
            mp[b[i]]++;
            swap(a[i],a[n-1]);
            swap(b[i],b[n-1]);
            n--;i--;
        }
    }
    //cout<<num<<endl;
    int dp[2048]={0},save[2048]={0};
    dp[0]=1;//cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2048;j++)save[j^b[i]]=dp[j];
        for(int j=0;j<2048;j++)dp[j]+=save[j];
        for(int j=0;j<2048;j++)dp[j]%=mod;//cout<<dp[0]<<endl;
    }
    ll ans=dp[0];
    for(auto pr:mp)
    {
        if(pr.second)
            ans=ans*_2[pr.second-1]%mod;
    }
    cout<<(ans+mod-1)%mod<<endl;
    return 0;
}