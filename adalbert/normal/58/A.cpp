#include <bits/stdc++.h>


using namespace std;
 long long a,k_,k,l,m,n,sw,s,l_,m_,t,z[100000],sum,sum_,x,z_,x1,x2,y2,y1_,b,p,q,dp[10000][10];
 string st;
int main()
{
   cin>>st;
   for (int i=0;i<st.length();i++)
   {
       if (st[i]=='h' || dp[i-1][1]==1) dp[i][1]=1;
       if ((st[i]=='e' && dp[i-1][1]==1) || dp[i-1][2]==1) dp[i][2]=1;
       if ((st[i]=='l' && dp[i-1][2]==1) || dp[i-1][3]==1) dp[i][3]=1;
       if ((st[i]=='l' && dp[i-1][3]==1) || dp[i-1][4]==1) dp[i][4]=1;
       if ((st[i]=='o' && dp[i-1][4]==1) || dp[i-1][5]==1) dp[i][5]=1;
   }
   if (dp[st.length()-1][5]==1) cout<<"YES"; else cout<<"NO";
}