#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
ll solve(int n,char s[])
{
    if(n==1)return 1;
    int len=(1<<(n-1))-1;
    int i;
    ll ans1=solve(n-1,s+1),ans2=solve(n-1,s+len+1);
    for(i=0;i<len;i++)if(s[i+1]!=s[i+len+1])break;
    if(i==len)return ans1*ans2%mod;
    else
    {
        if(s[i+1]>s[i+len+1])
        {
            for(i=0;i<len;i++)swap(s[i+1],s[i+len+1]);
        }
        return 2*ans1*ans2%mod;
    }
}
char s[1000006];
char t[1000006];
int nn,n;
void dfs(int i)
{
    if(i>=(1<<n))return;
    t[nn++]=s[i-1];
    dfs(i*2);
    dfs(i*2+1);
}
int main()
{
    cin>>n;
    scanf("%s",s);
    dfs(1);
    cout<<solve(n,t)<<endl;
    return 0;
}