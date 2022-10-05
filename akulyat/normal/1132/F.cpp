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
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

ll dp[kk][kk];
ll n,i,j;
vector <ll> m;
bool viv=false;
string s;

void split(string &s)
{
string ans;
ans+=s[0];
for (ll i=1; i<s.size(); i++)
  if (s[i]!=s[i-1])
    ans+=s[i];
s=ans;
}

void solve()
{
for (ll i=0; i<n; i++)
  dp[i][i]=1;
for (ll len=1; len<n; len++)
  for (ll l=0; l<n-len; l++)
    {
    ll r=l+len;
    ll lans=dp[l][r-1]+1;
    for (ll i=l; i<r; i++)
      if (s[i]==s[r])
        lans=min(dp[i+1][r-1]+dp[l][i], lans);
    dp[l][r]=lans;
//    cout<<l<<' '<<r<<": "<<dp[l][r]<<endl;
    }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
split(s);
n=s.size();
solve();
cout<<dp[0][n-1];






    return 0;
}