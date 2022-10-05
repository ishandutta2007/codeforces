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
vector <ll> p[3];
bool viv=false;
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n=s.size();
for (ll i=0; i<n; i++)
  m.push_back(s[i]-'a'),
  p[m[i]].push_back(i);

ll l=-1;
ll r=n;
vector <ll> have;
pll it[3];
it[0].F=0;
it[1].F=0;
it[2].F=0;
for (ll i=0; i<3; i++)
  it[i].S=(ll)p[i].size()-1;

while (have.size()<n/2)
  {
  for (ll b=0; b<3; b++)
    while (it[b].F<p[b].size()&&p[b][it[b].F]<=l)
      it[b].F++;
  for (ll b=0; b<3; b++)
    while (it[b].S>=0&&p[b][it[b].S]>=r)
      it[b].S--;
  vector <ll> los(3, inf);
  for (ll b=0; b<3; b++)
    if (it[b].F<=it[b].S)
      los[b]=0;
  for (ll b=0; b<3; b++)
    if (it[b].F<=it[b].S)
      los[b]+=p[b][it[b].F]-l-1,
      los[b]+=r-p[b][it[b].S]-1;
  ll c=0;
  for (ll b=0; b<3; b++)
    if (los[b]<=2)
      c=b;
  if (viv)
    {
    for (auto i:los)
      cout<<i<<' ';
    cout<<endl;
    cout<<"choose "<<c<<" with "<<it[c].F<<' '<<it[c].S<<' '<<p[c][it[c].F]<<' '<<p[c][it[c].S]<<endl;
    }
  have.push_back(p[c][it[c].F]);
  if (it[c].F!=it[c].S)
    have.push_back(p[c][it[c].S]);
  l=p[c][it[c].F];
  r=p[c][it[c].S];
  }
sort(have.begin(), have.end());

string ans;
for (auto i:have)
  ans+=s[i];
cout<<ans<<endl;






    return 0;
}