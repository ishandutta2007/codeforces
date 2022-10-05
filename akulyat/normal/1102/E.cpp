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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ll> m,p;
bool viv=false;
map <ll, vector <ll> > mp;
set <ll> s;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  s.insert(a);
  mp[a].push_back(i);
  }
for (ll i=0; i<n; i++)
  p.push_back(i);
for (auto i:s)
  {
  p[mp[i][0]]=max(p[mp[i][0]], mp[i].back());
  }
/*
for (auto i:p)
  cout<<i<<' ';
cout<<endl;
// */
vector <ll> st;
ll j=0;
ll ans=1;
for (ll i=0; i<n; i++)
  {
  if (st.empty()||st.back()<p[i])
    st.push_back(p[i]);
  while (j<st.size()&&st[j]<=i)
    j++;
  if (j==st.size())
    ans*=2;
  ans%=mod;
  }
if (ans&1)
  ans+=mod;
ans/=2;
cout<<ans<<endl;









    return 0;
}