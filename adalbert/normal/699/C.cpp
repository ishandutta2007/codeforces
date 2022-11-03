#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long  n,ans,a[300000],mn,ol,or_,m,pj,si,p[10000],s[10000],dp[10000][5];
string st[10000];
string s_ch(long long u, long long osn)
{
    string s="";
    while (u!=0)
    {
        s+=u%osn+48;
        u/=osn;
    }
    return(s);
}
bool paliandrom(string s)
{
    int k=0;
 //   for (int i=0;i<st.length()/2;i++)
 //       if (st[i]!=st[st.length()-i-1]) k++;
    if (k==0) return(1); else return(0);
}
long long perev(string s)
{
    int f=1;
    long long ans=0;
    for (int i=s.length()-1;i>=0;i--)
    {
        ans+=(s[i]-48)*f;
        f*=10;
    }
    return(ans);
}
bool check(long long u)
{
    int k=0;
    for (int i=2;i<=sqrt(u);i++)
        if (u%i==0) k++;
    if (k==0) return(true); else return(false);
}
bool ch(char i, char j)
{
    if (i>j) return(1); else return(0);
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>a[i]; a[i]++; }
    for (int i=1;i<=n;i++)
        if (a[i]==1)
        {
            dp[i][1]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]))+1;
            dp[i][2]=100000;
            dp[i][3]=100000;
        } else
        if (a[i]==2)
        {
            dp[i][1]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]))+1;
            dp[i][2]=min(dp[i-1][1],min(dp[i-1][2]+1,dp[i-1][3]));
            dp[i][3]=100000;
        } else
        if (a[i]==3)
        {
            dp[i][1]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]))+1;
            dp[i][3]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]+1));
            dp[i][2]=100000;
        } else
        {
            dp[i][1]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]))+1;
            dp[i][3]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]+1));
            dp[i][2]=min(dp[i-1][1],min(dp[i-1][2]+1,dp[i-1][3]));
        }
        //for (int i=1;i<=n;i++)
        cout<<min(dp[n][1],min(dp[n][3],dp[n][2]));
}