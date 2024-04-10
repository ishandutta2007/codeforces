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


ll n,i,j;
vector <string> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
  string a;
  getline(cin, a);
for (i=0; i<n; i++)
  {
  string a;
  getline(cin, a);
  m.push_back(a);
  }
vector <bool> can(26, true);
ll ans=0;
for (i=0; i<n; i++)
  {
  bool shok=false;
  string s=m[i].substr(2, m[i].size()-2);
  if (m[i][0]=='!')
    shok=true;
  if (m[i][0]=='?'&&i!=n-1)
    shok=true;
  {
  ll kol=0;
  for (auto u:can)
    if (u)
      kol++;
  if (kol==1&&shok)
    ans++;
//  cout<<i<<' '<<shok<<' '<<kol<<endl;
  }
  if (m[i][0]=='?')
    {
    for (j=0; j<26; j++)
      if (j==s[0]-'a')
        can[j]=false;
    }
  else
    {

    if (m[i][0]=='!')
      {
      vector <bool> was(26, false);
      for (auto c:s)
        was[c-'a']=true;
      for (ll u=0; u<26; u++)
        can[u]=(can[u]&was[u]);
      }
    else
      {
      for (auto c:s)
        can[c-'a']=false;
      }
    }
  }

cout<<ans<<endl;

    return 0;
}