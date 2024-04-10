#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
string s,s1,s2,ss1,ss2,s3,s4;
char cc;
ll a[10000],b[10000],v[10000],c,a1,b1,c1,n,m,x,i,j,sc,ans,k,fl,dp;
void vout()
{
    cout << "YES" << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);



  cin >> n >> m;
  for(i=0;i<n;i++)
  {
     cin >> cc;
     k=cc-'A'+1;
     b[k]=i+1;
   if(a[k]==0)a[k]=i+1;
  }
  for(i=1;i<=n;i++)
  {
      sc=0;
      fl=0;
      for(j=1;j<=26;j++)
      {
         if(b[j]<i)v[j]=0;
        if(v[j]==1)fl++;
      }
      dp=m-fl;
      if(dp<0)vout();
      for(j=1;j<=26;j++)if(v[j]==0 and a[j]<=i and b[j]>=i)
      {
          dp--;
          if(dp<0)vout();
          v[j]=1;
      }
  }
  cout << "NO" << endl;
return 0;
}