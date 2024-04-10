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
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char c[1000][1000];
ll dp[10000][1000],k,ans,sc,n,m,i,j,a[1000000],b[100000],a1,b1,c1,mx;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll uk;
   cin >> n >> k;
   mx=k;
   dp[0][0]=k;
   for(i=0;i<n;i++)cin >> a[i];
   sort(a,a+n);
   for(i=0;i<n;i++)
   {
       for(j=0;j<200;j++)if(dp[i][j]!=0)
       {
           k=dp[i][j];
           sc=0;
           while(k<(a[i]+1)/2)k*=2,sc++;
           dp[i+1][j+sc]=max(dp[i+1][j+sc],max(k,a[i]));
       }
   }
   for(i=0;i<200;i++)if(dp[n][i]!=0)
   {
       cout << i << endl;
       break;
   }
    return 0;
}