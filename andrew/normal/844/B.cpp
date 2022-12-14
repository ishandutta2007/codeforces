#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
const ll maxn=1000000;
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll t[100][100],tt[100][100],k,c,sc,n,m,i,j,a[100][100],b[100][100],t1[100][100],t2[100][100],a1,b1,c1,ans,x;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll i1,j1;
   cin >> n >> m;
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)cin >> a[i][j];
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
   {
        for(i1=i;i1<=n;i1++)if(a[i][j]==a[i1][j])t[i][j]++;
        for(i1=j;i1<=m;i1++)if(a[i][j]==a[i][i1])tt[i][j]++;
   }
   for(i=1;i<=n;i++)for(j=1;j<=m;j++)
   {
      ll fl=0;
      if(t1[i][j]==0)
      {
          ans+=(1ll<<t[i][j]);
          for(i1=i;i1<=n;i1++)if(a[i][j]==a[i1][j])
          {
              t1[i1][j]=1;
              if(t2[i1][j]==1)ans--;
          }
          ans--;
      }
      if(t2[i][j]==0)
      {
            ans+=(1ll<<tt[i][j]);
            ans--;
            for(i1=j;i1<=m;i1++)if(a[i][j]==a[i][i1])
            {
                t2[i][i1]=1;
                if(t1[i][i1]==1)ans--;
            }
      }

   }
   cout << ans << endl;
    return 0;
}