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
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n=s.size();
if (s[0]=='o')
  m.push_back(0);
ll kol=0;
for (ll i=0; i<n; i++)
  {
  kol++;
  if (i&&s[i]!=s[i-1])
    m.push_back(kol), kol=0;
  }
ll w=0;
for (ll i=1; i<n; i++)
  if (s[i]=='v'&&s[i]==s[i-1])
    w++;

ll pr=0;
ll ans=0;
for (ll i=1; i<n; i++)
  {
  if (s[i]=='v'&&s[i]==s[i-1])
    pr++;
  if (s[i]=='o')
    ans+=pr*(w-pr);
  }
cout<<ans<<endl;


    return 0;
}