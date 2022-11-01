#include <bits/stdc++.h>

using namespace std;

const int N=20005;
int tree[4*N];
int lazy[4*N];

void push(int idx)
{
    tree[2*idx]+=lazy[idx];
    lazy[2*idx]+=lazy[idx];
    tree[2*idx+1]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=val;
        lazy[idx]+=val;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[n+1][m+1];
    for(int o=1;o<=n;o++) for(int i=1;i<=m;i++) scanf("%d",&a[o][i]);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int sum=0;
    for(int i=m;i>m-k;i--) sum+=a[n][i];
    dp[n][m-k+1]=sum;
    for(int i=m-k;i>=1;i--)
    {
        sum-=a[n][i+k];
        sum+=a[n][i];
        dp[n][i]=sum;
    }
    for(int o=n-1;o>=1;o--)
    {
        sum=0;
        for(int i=m;i>m-k;i--) sum+=a[o+1][i];
        update(1,1,m,m-k+1,m-k+1,dp[o+1][m-k+1]-sum);
        for(int i=m-k;i>=1;i--)
        {
            if(i+k>m-k) sum-=a[o+1][i+k];
            update(1,1,m,i,i,dp[o+1][i]-sum);
        }
        sum=0;
        for(int i=m;i>m-k;i--) sum+=(a[o][i]+a[o+1][i]);
        dp[o][m-k+1]=sum+tree[1];
        for(int i=m-k;i>=1;i--)
        {
            sum-=(a[o][i+k]+a[o+1][i+k]);
            sum+=(a[o][i]+a[o+1][i]);
            update(1,1,m,i+1,i+k,a[o+1][i+k]);
            update(1,1,m,max(1,i-k+1),i,-a[o+1][i]);
            dp[o][i]=sum+tree[1];
        }
        for(int i=0;i<4*N;i++) tree[i]=lazy[i]=0;
    }
    int res=0;
    for(int i=1;i<=m;i++) res=max(res,dp[1][i]);
    printf("%d\n",res);
    return 0;
}