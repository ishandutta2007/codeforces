#include"bits/stdc++.h"
using namespace std;
int a[100005];
int n,m;
void solve(int t)
{
    while(1)
    {
        if(a[m-t])a[m-t]--;
        else break;
        t=a[m-t];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<int,int>mp;
        cin>>n>>m;
        for(int i=0;i<=m;i++)a[i]=0;
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            t%=m;
            a[t]++;
        }
        int ans=0;/*
        for(int i=0;i<m;i++)
        {
            if(a[i])
            {
                a[i]--;
                ans++;
                solve(i);
                solve(i);
            }
        }*/
        if(a[0])ans++;
        if(m%2==0&&a[m/2])ans++;
        for(int i=1;2*i<m;i++)
        {
            int n1=a[i],n2=a[m-i];
            if(n1>n2)swap(n1,n2);
            if(n2>0)
            {
                ans++;
                n2-=n1+1;
                ans+=max(n2,0);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}