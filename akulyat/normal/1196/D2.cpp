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
string s;
vector <ll> m;
vector <ll> p[3][3];
bool viv=false;

void prepare()
{
for (ll i=0; i<3; i++)
  for (ll j=0; j<3; j++)
    p[i][j].clear();
for (ll i=0; i<3; i++)
  for (ll j=0; j<3; j++)
    p[i][j].push_back(0);
for (ll i=0; i<n; i++)
  {
  for (ll j=0; j<3; j++)
    for (ll u=0; u<3; u++)
      p[j][u].push_back(p[j][u].back());
  p[i%3][s[i]-'0'].back()++;
  }
}

ll ins(ll l, ll r, ll c, ll m3)
{
ll kol=0;
kol+=p[m3][c][r+1];
kol-=p[m3][c][l];
return kol;
}

ll mini(ll l, ll r)
{
ll ans[3]={0, 0, 0};
ans[0]+=ins(l, r, 0, 0);
ans[0]+=ins(l, r, 1, 1);
ans[0]+=ins(l, r, 2, 2);
ans[1]+=ins(l, r, 0, 1);
ans[1]+=ins(l, r, 1, 2);
ans[1]+=ins(l, r, 2, 0);
ans[2]+=ins(l, r, 0, 2);
ans[2]+=ins(l, r, 1, 0);
ans[2]+=ins(l, r, 2, 1);
return k-*max_element(ans, ans+3);
}

ll calc()
{
ll lans=mod;
for (ll i=k-1; i<n; i++)
  lans=min(lans, mini(i-k+1, i));
return lans;
}

void solve()
{
cin>>n>>k;
cin>>s;
for (auto &c:s)
  {
  if (c=='R')
    c='0';
  if (c=='G')
    c='1';
  if (c=='B')
    c='2';
  }
prepare();
ll lans=calc();
cout<<lans<<endl;
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