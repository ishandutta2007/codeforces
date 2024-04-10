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
vector <ll> bef[10*kk];
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n-1; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--; b--;
  if (a!=n-1&&b!=n-1||(a==b))
    {
    cout<<"NO";
    return 0;
    }
  if (a>b)
    swap(a, b);
  m.push_back(a);
  }

sort(m.begin(), m.end());
vector <ll> kol(n, 0);
for (auto i:m)
  kol[i]++;


for (i=0; i<n; i++)
  if (kol[i]>i+1)
    {
    cout<<"NO";
    return 0;
    }

vector <ll> st;
vector <pll> re;
for (i=0; i<n-1; i++)
  {
  if (kol[i]==0)
    st.push_back(i);
  if (kol[i]-1>st.size())
    {
    cout<<"NO";
    return 0;
    }
  if (kol[i]>0)
    {
    ll j=kol[i]-1;
    bef[i].push_back(n-1);
    while (j)
      {
      bef[i].push_back(st.back());
//      bef[i].push_back()
      st.pop_back();
      j--;
      }
    }
  }
for (i=0; i<n; i++)
  if (!bef[i].empty())
    {
    for (j=1; j<bef[i].size(); j++)
      re.push_back({bef[i][j-1], bef[i][j]});
    re.push_back({i, bef[i].back()});
    }


 /*
if (!st.empty())
  {
  cout<<"NO";
  return 0;
  }
// */

cout<<"YES"<<endl;
for (auto i:re)
  cout<<i.S+1<<' '<<i.F+1<<'\n';






    return 0;
}