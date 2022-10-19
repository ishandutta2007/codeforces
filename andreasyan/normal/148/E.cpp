#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n,m;
int s[N];
int a[N][N];

int dp[N*N];
bool c[N*N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        for(int j=1;j<=s[i];++j)
            cin>>a[i][j];
    }
    c[0]=true;
    for(int i=0;i<n;++i)
    {
        int p[N]={};
        int sum=0;
        for(int j=1;j<=s[i];++j)
        {
            p[j]=p[j-1]+a[i][j];
            sum+=a[i][j];
        }
        int maxu[N]={};
        for(int r=1;r<=s[i];++r)
        {
            for(int l=1;l<=r;++l)
            {
                maxu[s[i]-(r-l+1)]=max(maxu[s[i]-(r-l+1)],sum-(p[r]-p[l-1]));
            }
        }
        maxu[s[i]]=sum;
        for(int j=m;j>=0;--j)
        {
            for(int k=1;k<=s[i];++k)
            {
                if(c[j])
                {
                    if(j+k<=m)
                    {
                        c[j+k]=true;
                        dp[j+k]=max(dp[j+k],dp[j]+maxu[k]);
                    }
                }
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}