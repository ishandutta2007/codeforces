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
vector <string> m;
bool viv=false;
vector <ll> buk[10*kk];
ll kol[3*kk][3*kk];


void zap()
{
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    if (i||j)
      {
      kol[i][j]=mod;
      if (i)
        kol[i][j]=min(kol[i-1][j]+(m[i-1][j]!='a'), kol[i][j]);
      if (j)
        kol[i][j]=min(kol[i][j-1]+(m[i][j-1]!='a'), kol[i][j]);
      }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  string ss;
  cin>>ss;
  for (j=0; j<n; j++)
    buk[i+j].push_back(ss[j]-'a');
  m.push_back(ss);
  }
set <ll> can;
vector <ll> s;
for (i=0; i<n; i++)
  s.push_back(i+1);
for (i=n-1; i>0; i--)
  s.push_back(i);
string ans;
zap();
ll from=0;
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    if (kol[i][j]<=k)
      from=max(from, i+j);
if (kol[n-1][n-1]<k)
  from=2*n-1;
ll mk=0;
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
  if (i+j==from)
    {
    if (kol[i][j]<=k)
      can.insert(mk);
    mk++;
    }
for (j=0; j<from; j++)
  ans+='a';
for (i=from; i<2*n-1; i++)
  {
  vector <pll> v;
  for (auto p:can)
    if (p>=0&&p<s[i])
      v.push_back({buk[i][p], p});
  can.clear();
  sort(v.begin(), v.end());
  ans+=char('a'+v[0].F);
  for (j=0; j<v.size(); j++)
    if (v[j].F==v[0].F)
      {
      ll p=v[j].S;
      can.insert(p);
      ll p2=p+1;
      if (i>=n-1)
        p2=p-1;
      can.insert(p2);
      }
  }
cout<<ans;


    return 0;
}