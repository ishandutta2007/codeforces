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


ll n,i,j, m;
vector <vector <ll>> ans;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
ans.resize(m);
for (auto &v:ans)
  v.resize(26);
for (i=0; i<n; i++)
  {
  string st;
  cin>>st;
  for (ll j=0; j<m; j++)
    ans[j][st[j]-'A']++;
  }
ll answ=0;
for (ll i=0; i<m; i++)
  {
  ll pr;
  cin>>pr;
  ll ma=0;
  for (ll j=0; j<26; j++)
    ma=max(ma, ans[i][j]);
  answ+=ma*pr;
  }
cout<<answ;


    return 0;
}