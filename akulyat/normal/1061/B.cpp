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
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll lh;
cin>>n>>lh;
ll kol=0;
ll sum=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  if (a)
    kol++;
  sum+=a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
ll ma=m.back();
m.pop_back();
ll ans=sum-ma-kol+1;
ll lev=1;
for (auto i:m)
  if (i>=lev&&lev<ma)
    ans++, lev++;
cout<<ans;





    return 0;
}