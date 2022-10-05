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


ll n,l,i,j,d;
vector <pll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l>>d;
d++;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back({a, i});
  }
sort(m.begin(), m.end());

ll a=0;
ll b=n;

while (a+1!=b)
  {
  ll mi=a+b>>1;
  bool good=true;
  for (j=0; j<n-mi; j++)
    if (m[j+mi].F-m[j].F<d)
      good=false;
  if (good)
    b=mi;
  else
    a=mi;
  }

cout<<b<<endl;
vector <ll> ans(n, 0);
for (i=0; i<n; i++)
  ans[m[i].S]=i%b;
for (auto i:ans)
  cout<<i+1<<' ';







    return 0;
}