#include"bits/stdc++.h"
using namespace std;
int a[200005];
int n,k;
int b[200005];
int vis[200005];
int judge(int num,int k,int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]<=k)vis[i]=1;
        else vis[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        if(vis[i-1]==1&&vis[i]==1)vis[i]=0;
    }
    for(int i=0;i<n;i++)num-=vis[i];
    if(num<=0)return 1;
    return 0;
}
int solve(int num,int *a,int n)
{
    for(int i=0;i<n;i++)b[i]=a[i];
    sort(b,b+n);
    int x1=-1,x2=n-1;
    while(x1+1!=x2)
    {
        int x=(x1+x2+1)/2;
        if(judge(num,b[x],a,n))x2=x;
        else x1=x;
    }
    return b[x2];
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int n1,n2;
    n2=k/2;
    n1=k-n2;
    int ans;
    if(n1==n2)ans=min(solve(n1,a,n-1),solve(n1,a+1,n-1));
    else ans=min(solve(n1,a,n),solve(n2,a+1,n-2));
    cout<<ans<<endl;
    return 0;
}