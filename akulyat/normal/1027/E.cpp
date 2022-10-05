#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j,k;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
k--;
vector <ll> st(1, 1);
for (i=1; i<=10*kk; i++)
  st.push_back((st.back()*2)%mod);

vector <ll> ans[n+1];
ans[0].push_back(1);
for (i=1; i<=n; i++)
  ans[0].push_back(0);
vector <ll> sum[n+1];
sum[0].push_back(ans[0][0]);
for (i=1; i<=n; i++)
  sum[0].push_back(sum[0].back()+ans[0][i]);
for (i=1; i<=n; i++)
  {
  ans[i].push_back(0);
  sum[i].push_back(0);
  for (j=1; j<i; j++)
    {
    ans[i].push_back(ans[i-1][j]*2);
    ans[i][j]-=sum[i-1-j][j];
    ans[i][j]+=sum[i-j][j-1];
    ans[i][j]+=mod;
    ans[i][j]%=mod;
//    cout<<i<<' '<<j<<':'<<ans[i-1][j]*2<<' '<<-sum[i-1-j][j]<<' '<<ans[i-j][j]<<endl;
    }
  ans[i].push_back(1);
  for (j=i+1; j<=n; j++)
    ans[i].push_back(0);
  for (j=1; j<=n; j++)
    sum[i].push_back((sum[i].back()+ans[i][j])%mod);
  }

/*
for (i=0; i<=n; i++)
  {
  for (auto v:ans[i])
    cout<<v<<' ';
  cout<<endl;
  }
cout<<endl;
for (i=0; i<=n; i++)
  {
  for (auto v:sum[i])
    cout<<v<<' ';
  cout<<endl;
  }
cout<<endl;
*/

ll otv=0;
for (j=1; j<=n; j++)
  {
  ll ost=k/j;
  ost=min(ost, n);
  otv+=ans[n][j]*sum[n][ost];
  otv%=mod;
  }
otv*=2;
otv%=mod;
cout<<otv<<endl;




    return 0;
}