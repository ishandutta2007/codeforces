#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <ll> m;
bool viv=false;
map <ll, ll> mp;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }

vector <ll> sum;
sum.push_back(0);
for (i=0; i<n; i++)
  sum.push_back(sum.back()+m[i]);
for (auto i:sum)
  mp[i]++;

ll s=0;
ll ans=0;
for (i=n-1; i>=0; i--)
  {
  s+=m[i];
  mp[sum.back()]--;
  sum.pop_back();
  if (mp.find(s)!=mp.end())
    if (mp[s]!=0)
      ans=s;
  }
cout<<ans;

    return 0;
}