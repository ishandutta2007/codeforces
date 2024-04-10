#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
using namespace std;
vector <ll> a[100001],dp[100001];
ll b[100000],v[100000],x,i,j,n,m,k,sc,mx,mn,l,r,dp1[1000000];
string s,s1,s2;
char c,c1,c2;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for(i=0;i<n;i++)for(j=0;j<m;j++)
  {
      cin >> x;
      a[i].p_b(x);
  }
  for(i=0;i<m;i++)dp[0].p_b(1);
  for(i=1;i<n;i++)
  {
      for(j=0;j<m;j++)if(a[i][j]>=a[i-1][j])dp[i].p_b(1); else dp[i].p_b(0);
  }
  //dp1[n]=n;
  for(i=0;i<m;i++)
  {
      mx=n-1;
    for(j=n-1;j>-1;j--)
    {
        dp1[j]=max(dp1[j],mx);
        //if(j==0)cout << mx << " " << i << endl;
        if(dp[j][i]==0)mx=j-1;
    }
  }
  cin >> k;
  for(i=0;i<k;i++)
  {
      cin >> l >> r;
      if(dp1[l-1]>=r-1)cout << "Yes"; else cout << "No";
      cout << endl;
  }
  return 0;
}