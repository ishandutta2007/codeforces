#include"bits/stdc++.h"
using namespace std;
double dp[2004][2004];
map<int,int>l,r;
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        l[u]=1;
        r[v]=1;
    }
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=dp[i][0]=dp[i-1][0]+n/(double)i;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        dp[i][j]=((n-j)*i*dp[i-1][j]+(n-i)*j*dp[i][j-1]+i*j*dp[i-1][j-1]+n*n)/((n-j)*i+(n-i)*j+i*j);
    }//cout<<n-r.size()<<n-l.size()<<endl;
    printf("%lf\n",dp[n-l.size()][n-r.size()]);
    return 0;
}