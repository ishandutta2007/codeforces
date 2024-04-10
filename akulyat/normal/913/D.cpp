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


ll n,i,j,T;
vector <ll> t,p;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>T;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  p.push_back(a);
  t.push_back(b);
  }

ll a=0;
ll b=n+1;
while (a+1!=b)
  {
  ll mi=a+b>>1;
  vector <ll> v;
  for (i=0; i<n; i++)
    if (p[i]>=mi)
      v.push_back(t[i]);
  sort(v.begin(), v.end());
  bool good=true;
  if (v.size()<mi)
    good=false;
  while (v.size()>mi)
    v.pop_back();
  ll sum=0;
  for (auto i:v)
    sum+=i;
  if (sum>T)
    good=false;
  if (good)
    a=mi;
  else
    b=mi;
  }

ll mi=a;
cout<<mi<<endl;
cout<<mi<<endl;
vector <pll> v;
for (i=0; i<n; i++)
  if (p[i]>=mi)
    v.push_back({t[i], i});
sort(v.begin(), v.end());
for (i=0; i<mi; i++)
  cout<<v[i].S+1<<' ';







    return 0;
}