#include"bits/stdc++.h"
using namespace std;
bool dp[44][44][44][44];
int st[44][44][44][44];
char s[105];
int n,a,b;
void pr(int p,int i,int j,int k)
{
    if(p==0)return;
    if(st[p][i][j][k]<0)
    {
        pr(p-1,i,-st[p][i][j][k]-1,k-1);
        putchar('B');
    }
    else
    {
        pr(p-1,st[p][i][j][k]-1,j,k);
        putchar('R');
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>s+1;
        dp[0][0][0][0]=1;
        for(int p=1;p<=n;p++)
        {
            for(int k=0;k<=40;k++)for(int i=0;i<a;i++)for(int j=0;j<b;j++)if(dp[p-1][i][j][k])
            {//cout<<"<<<"<<p-1<<" "<<i<<" "<<j<<" "<<k<<endl;
                dp[p][(i*10+s[p]-'0')%a][j][k]=1;
                st[p][(i*10+s[p]-'0')%a][j][k]=i+1;
                dp[p][i][(j*10+s[p]-'0')%b][k+1]=1;//cout<<p<<" "<<(i*10+s[p]-'0')%a<<" "<<j<<" "<<k<<endl;
                st[p][i][(j*10+s[p]-'0')%b][k+1]=-j-1;//cout<<p<<" "<<i<<" "<<(j*10+s[p]-'0')%b<<" "<<k+1<<endl;
            }
        }
        int now=1e9;
        int d=-1;
        for(int i=1;i<n;i++)if(dp[n][0][0][i])
        {
            if(abs(n-2*i)<now)
            {
                now=abs(n-2*i);
                d=i;
            }
        }
        if(d!=-1)
        {
            pr(n,0,0,d);
            cout<<endl;
        }
        else cout<<-1<<endl;
        for(int i=0;i<41;i++)for(int j=0;j<41;j++)for(int k=0;k<41;k++)for(int p=0;p<41;p++)dp[i][j][k][p]=0;
    }
    return 0;
}