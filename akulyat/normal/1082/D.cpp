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
vector <pll> reb;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll sum=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  sum+=a;
  m.push_back(a);
  }
if (sum<2*(n-1))
  {
  cout<<"NO\n";
  return 0;
  }

vector <ll> st;
for (i=0; i<n; i++)
  if (m[i]>1)
    st.push_back(i);
ll a=-1, b=-1;
ll kol=n-st.size();
if (kol==0)
  {
  a=st.back();
  st.pop_back();
  b=st.back();
  st.pop_back();
  }
if (kol==1)
  {
  a=st.back();
  st.pop_back();
  for(i=0; i<n; i++)
    if (m[i]==1)
      b=i, i=n;
  }
if (kol>1)
  {
  for(i=0; i<n; i++)
    if (m[i]==1)
      b=i, i=n;
  for(i=n-1; i>=0; i--)
    if (m[i]==1)
      a=i, i=-1;
  }
m[a]--;
m[b]--;
reb.push_back({a, st[0]});
reb.push_back({b, st.back()});
for (i=0; i<(ll)st.size()-1; i++)
  reb.push_back({st[i], st[i+1]});
for (auto i:st)
  m[i]-=2;
vector <bool> was(n, false);
was[a]=true;
was[b]=true;
for (auto i:st)
  was[i]=true;
for (i=0; i<n; i++)
  if (!was[i])
    {
    for (j=0; j<n; j++)
      if (was[j]&&m[i]>0&&m[j]>0)
        m[i]=0, m[j]--, reb.push_back({i, j});
    }
cout<<"YES ";
cout<<st.size()+1<<endl;
cout<<reb.size()<<endl;
for (auto i:reb)
  cout<<i.F+1<<' '<<i.S+1<<endl;

    return 0;
}