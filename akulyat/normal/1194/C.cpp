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
vector <ll> m;
bool viv=false;

string solve()
{
string s, t, p;
cin>>s>>t>>p;
vector <ll> need(26, 0);
vector <ll> have(26, 0);
for (auto i:t)
  need[i-'a']++;
for (auto i:p)
  have[i-'a']++;
for (auto i:s)
  need[i-'a']--;
for (auto i:need)
  if (i<0)
    return "NO";
for (ll i=0; i<26; i++)
  if (have[i]<need[i])
    return "NO";

ll i=0, j=0;
while (i<s.size()&&j<t.size())
  if (s[i]==t[j])
    i++, j++;
  else
    j++;
if (i!=s.size())
  return "NO";
return "YES";
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t--)
  cout<<solve()<<'\n';

    return 0;
}