#include <bits/stdc++.h>
using namespace std;
const int N=5005;

int n,q;
int a[N];

int ans[N][N];
int yans[N][N];

int dp[N][N];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        dp[0][i]=a[i];
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<(n-i)-1;++j)
            dp[i+1][j]=dp[i][j]^dp[i][j+1];
    }
    for(int r=0;r<n;++r)
    {
        for(int l=0;l<=r;++l)
        {
            ans[l][r]=dp[r-l][l];
        }
    }
    for(int s=1;s<=n;++s)
    {
        for(int r=s-1;r<n;++r)
        {
            int l=r-s+1;
            yans[l][r]=max(yans[l+1][r],yans[l][r-1]);
            yans[l][r]=max(yans[l][r],ans[l][r]);
        }
    }
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        cout<<yans[l][r]<<endl;
    }
    return 0;
}