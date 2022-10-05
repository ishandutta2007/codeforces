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


ll n,i,j,k;
vector <ll> m[26];
bool viv=false;
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k>>s;
s+='#';
string t;
for (ll i=0; i<n; i++)
  {
  t+=s[i];
  if (s[i]!=s[i+1])
    m[s[i]-'a'].push_back(t.size()), t="";
  }
vector <ll> ans;
for (ll i=0; i<26; i++)
  {
  ll lans=0;
  for (auto val:m[i])
    lans+=(val/k);
  ans.push_back(lans);
  }
cout<<*max_element(ans.begin(), ans.end());

    return 0;
}