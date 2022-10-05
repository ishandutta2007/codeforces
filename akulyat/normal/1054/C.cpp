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
vector <ll> m,l,r;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  l.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  r.push_back(a);
  }
for (i=0; i<n; i++)
  m.push_back(0);
ll ma=-1;
for (i=0; i<n; i++)
  ma=max(ma, l[i]+r[i]);
for (i=0; i<n; i++)
  {
  m[i]=ma-l[i]-r[i]+1;
  }
set <ll> s;
vector <ll> v;
for (auto i:m)
  s.insert(i);
for (auto i:s)
  v.push_back(i);
for (i=0; i<n; i++)
  {
  ll fl=0;
  ll fr=0;
  for (j=0; j<i; j++)
    if (m[j]>m[i])
      fl++;
  for (j=i+1; j<n; j++)
    if (m[j]>m[i])
      fr++;
  if (fl!=l[i]||fr!=r[i])
    {
    cout<<"NO";
    return 0;
    }
  }
cout<<"YES"<<endl;
for (auto i:m)
  cout<<i<<' ';





    return 0;
}