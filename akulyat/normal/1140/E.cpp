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


ll n,i,j, k;
vector <ll> m[2], step;
bool viv=false;
ll dp[2][ml];

void prepare()
{
step.push_back(1);
for (ll i=1; i<ml; i++)
  step.push_back(step.back()*(k-1)), step.back()%=mod;

dp[0][0]=1;
dp[1][0]=0;
for (i=1; i<=n; i++)
  for (j=0; j<2; j++)
    {
    dp[j][i]=step[i];
    dp[j][i]-=dp[j][i-1];
    if (dp[j][i]<0)
      dp[j][i]+=mod;
    }
}

ll vars(ll kol, bool same)
{
return dp[same][kol];
}

ll solve(vector <ll> & m)
{
ll n=m.size();
ll ans=k;
bool easy=true;
for (ll i=0; i<n; i++)
  {
  if (i)
    ans*=k-1;
  ans%=mod;
  easy&=(m[i]==-1);
  }
if (easy)
  return ans;

ans=1;
while (m.back()==-1)
  ans*=k-1, ans%=mod, m.pop_back();
reverse(m.begin(), m.end());
while (m.back()==-1)
  ans*=k-1, ans%=mod, m.pop_back();
reverse(m.begin(), m.end());
n=m.size();

vector <ll> v, kol;
kol.push_back(0);
for (ll i=0; i<n; i++)
  {
  if (m[i]==-1)
    kol.back()++;
  else
    v.push_back(m[i]), kol.push_back(0);
  }
for (ll i=0; i<v.size()-1; i++)
  {
  ll v1=v[i];
  ll v2=v[i+1];
  ll len=kol[i+1];
  ans*=vars(len, v1==v2);
  ans%=mod;
  }
return ans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m[i&1].push_back(a);
  }
prepare();

ll ans=1;
for (j=0; j<2; j++)
  ans*=solve(m[j]);
ans%=mod;
cout<<ans<<endl;








    return 0;
}