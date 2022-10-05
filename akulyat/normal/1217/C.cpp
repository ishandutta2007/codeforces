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


ll n,i,j, ans;
vector <ll> las;
string s;
bool viv=false;

void prepare()
{
las.clear();
las.push_back(0);
for (ll i=0; i<n; i++)
  las.push_back('1'-s[i]);
for (ll i=1; i<n; i++)
  if (las[i])
    las[i]+=las[i-1];
}

void check(ll l, ll r)
{
if (s[l]=='0')
  return;
r++;
if (viv)
  cout<<"Check "<<l<<' '<<r<<endl;
ll res=0;
for (ll i=l; i<r; i++)
  res<<=1, res+=s[i]-'0';
ll mi=r-l;
ll ma=mi+las[l];
if (mi<=res&&res<=ma)
  {
  ans++;
  if (viv)
    cout<<l<<' '<<r<<endl;
  }
}

void solve()
{
cin>>s;
n=s.size();
prepare();
ans=0;
for (ll i=0; i<n; i++)
  for (ll j=i; j<min(n, i+20); j++)
    check(i, j);
cout<<ans<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t--)
  solve();

    return 0;
}