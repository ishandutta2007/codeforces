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
vector <ll> m, c, o;
bool viv=false;
string s;
vector <pll> p;

void colour()
{
vector <ll> st;
for (ll i=0; i<n; i++)
  {
  if (s[i]=='(')
    st.push_back(i);
  else
    p.push_back({st.back(), i}), st.pop_back();
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
colour();
sort(p.begin(), p.end());
c.resize(n);
o.resize(n);
for (ll i=0; i<p.size(); i++)
  {
  c[p[i].F]=p[i].S;
  o[p[i].S]=p[i].F;
  }
if (viv)
  {
  for (auto i:c)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:o)
    cout<<i<<' ';
  cout<<endl;
  }
vector <ll> col;
col.resize(n);
ll lev=0;
for (ll i=0; i<n; i++)
  {
  if (s[i]=='(')
    {
    lev++;
    col[i]=lev&1;
    col[c[i]]=lev&1;
    }
  else
    lev--;
  }
for (auto i:col)
  cout<<i;





    return 0;
}