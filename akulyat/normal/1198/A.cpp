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


ll n,i,j, k;
vector <ll> m;
bool viv=false;

void my()
{
set <ll> s;
for (auto i:m)
  s.insert(i);
map <ll, ll> mp;
ll j=0;
for (auto i:s)
  {
  mp[i]=j;
  j++;
  }
for (auto &i:m)
  i=mp[i];
sort(m.begin(), m.end());
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
my();

k*=8;
k/=n;

k = 1ll << min(30ll, k);
//cout<<"lans is "<<k<<endl;
ll i=0, j=0;
ll ans=0;
while (i<n)
  {
  while (j<n&&m[j]-m[i]<k)
    j++;
  ans=max(j-i, ans);
  i++;
  }

cout<<n - ans<<endl;








    return 0;
}