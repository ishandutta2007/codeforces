#include"bits/stdc++.h"
using namespace std;
#define ll long long
int dp[2000005];
int solve(int m)
{
    int mm=m;
    if(mm%2==0)mm--;
    for(int i=1;i<=mm/2;i++)
    {
        dp[mm/2+1-i]=i;
        dp[i]=mm/2+1-i;
    }
    for(int i=1;i<=mm/2+1;i++)
    {
        dp[mm/2+2-i+mm/2]=i+mm/2;
        dp[i+mm/2]=mm/2+2-i+mm/2;
    }
    if(m!=mm)
    {
        dp[m]=m;
    }
    return mm/2+1;
    /*
    set<int>s;
    for(int i=1;i<=m;i++)
    {
        s.insert(i);
        dp[i]=0;
    }
    dp[1]=1;
    for(int i=2;i<=m;i++)if(dp[i]==0)
    {
        for(auto t:s)
        {
            if(i+t>m)break;
            if(dp[i+t]==0)
            {
                dp[i+t]=i;
                dp[i]=i+t;
                s.erase(s.find(t));
                break;
            }
        }
    }
    return (*s.begin());*/
}
ll save[100005];
int main()
{
    //solve(m)+m>=n
    //cout<<solve(1)<<endl;
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    int l=0,r=1e5;
    while(l+1!=r)
    {
        int m=l+r>>1;
        if(solve(m)+m>=n)r=m;
        else l=m;
    }
    solve(r);
    cout<<r<<endl;
    for(int i=1;i<=r;i++)
    {
        if(dp[i]==0)dp[i]=i;
        printf("%d %d\n",i,dp[i]);
    }
    return 0;
}