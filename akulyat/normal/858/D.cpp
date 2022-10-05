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
vector <string> s;
map <pll, vector<ll> > mp;
bool viv=false;

string ll_to_str(long long v)
{
string s="";
if (v==0)
  return "0";
bool obr=false;
if (v<0)
  obr=true;
v=abs(v);
while (v>0)
  {
  short e=v%10;
  s+=char('0'+e);
  v/=10;
  }
reverse(s.begin(), s.end());
if (obr)
  s='-'+s;
return s;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  string a;
  cin>>a;
  s.push_back(a);
  }

for (ll v=0; v<n; v++)
  {
  for (i=0; i<9; i++)
    {
    ll z=0;
    for (j=i; j<9; j++)
      {
      z*=10;
      z+=char(s[v][j]-'0');
      mp[{z, j-i+1}].push_back(v);
      if (mp[{z, j-i+1}].size()==2)
        if (mp[{z, j-i+1}][0]==mp[{z, j-i+1}][1])
          mp[{z, j-i+1}].pop_back();
      }
    }
  }


for (ll v=0; v<n; v++)
  {
  pll a={0, 10};
  for (i=0; i<9; i++)
    {
    ll z=0;
    for (j=i; j<9; j++)
      {
      z*=10;
      z+=char(s[v][j]-'0');
      if (mp[{z, j-i+1}].size()==1)
        if (j-i+1<a.S)
          a={z, j-i+1};
      }
    }
  string sans=ll_to_str(a.F);
  reverse(sans.begin(), sans.end());
  while (sans.size()<a.S)
    sans+='0';
  reverse(sans.begin(), sans.end());
  cout<<sans<<'\n';
  }

    return 0;
}