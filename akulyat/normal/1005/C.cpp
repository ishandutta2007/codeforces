#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <ll> m,st;
map <ll, ll> mp;
int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  mp[a]=0;
  }

for (auto i:m)
    mp[i]++;

st.push_back(1ll);
for (i=1; i<33; i++)
  st.push_back(st.back()*2);

ll ans=0;
for (i=0; i<n; i++)
  {
  ll v=m[i];
  ll add=1;
  for (ll j=0; j<33; j++)
    if (add==1)
      {
      ll s=st[j]-v;
      if (mp.find(s)!=mp.end())
        {
        add=0;
        if (v==s&&mp[s]==1)
          add=1;
        }
      }
  ans+=add;
  }

cout<<ans;




    return 0;
}