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


ll n,i,j, m, k, q;
vector <pll> s;
vector <ll> sf, l, r;
vector <ll> on[300*kk];
pll kr[300*kk];
ll len[300*kk];
set <ll> s_s;
vector <ll> vs;
vector <pll> ans;
bool viv=false;

void build()
{
ll now=-1;
ll j=0;
for (ll i=0; i<300*kk; i++)
  {
  if (j<sf.size()&&sf[j]==i)
    now=i, j++;
  l.push_back(now);
  }
now=300*kk;
j=0;
reverse(sf.begin(), sf.end());
for (ll i=300*kk-1; i>=0; i--)
  {
  if (j<sf.size()&&sf[j]==i)
    now=i, j++;
  r.push_back(now);
  }
reverse(sf.begin(), sf.end());
reverse(r.begin(), r.end());
}

ll path(pll p1, pll p2)
{
ll x1=p1.F;
ll y1=p1.S;
ll x2=p2.F;
ll y2=p2.S;
ll ans1=0, ans2=0;
if (l[x1]!=-1)
  {
  ans1+=abs(l[x1]-x1);
  ans1+=abs(l[x1]-x2);
  }
else
  ans1=mod;
if (r[x1]<250*kk)
  {
  ans2+=abs(r[x1]-x1);
  ans2+=abs(r[x1]-x2);
  }
else
  ans2=mod;
ans1+=abs(y2-y1);
ans2+=abs(y2-y1);
if (viv)
  cout<<"Path "<<x1<<' '<<y1<<'-'<<x2<<' '<<y2<<" is "<<min(ans1, ans2)<<endl,
  cout<<"Using "<<l[x1]<<' '<<r[x1]<<endl;
return min(ans1, ans2);
}

void solve(ll num)
{
ll y=vs[num];
ll wy=vs[num+1];
kr[y].F=on[y][0];
kr[y].S=on[y].back();
len[y]=abs(kr[y].F-kr[y].S);
if (wy==300*kk)
  {
  ans[num].F=len[y];
  ans[num].S=len[y];
  return;
  }

  {
  ll add=path({kr[y].S, y}, {kr[wy].F, wy});
  add+=ans[num+1].F;
  ans[num].F=add;
  }
  {
  ll add=path({kr[y].S, y}, {kr[wy].S, wy});
  add+=ans[num+1].S;
  ans[num].F=min(ans[num].F, add);
  }
  {
  ll add=path({kr[y].F, y}, {kr[wy].F, wy});
  add+=ans[num+1].F;
  ans[num].S=add;
  }
  {
  ll add=path({kr[y].F, y}, {kr[wy].S, wy});
  add+=ans[num+1].S;
  ans[num].S=min(ans[num].S, add);
  }

ans[num].F+=len[y];
ans[num].S+=len[y];
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k>>q;
for (ll i=0; i<k; i++)
  {
  ll a, b;
  cin>>a>>b;
  a--, b--;
  s.push_back({a, b});
  on[a].push_back(b);
  s_s.insert(a);
  }
s.push_back({0, 0});
on[0].push_back(0);
s_s.insert(0);
for (auto &v:on)
  sort(v.begin(), v.end());
for (ll i=0; i<q; i++)
  {
  ll a;
  cin>>a;
  a--;
  sf.push_back(a);
  }
sort(sf.begin(), sf.end());
sort(s.begin(), s.end());
build();
s_s.insert(300*kk);
for (auto i:s_s)
  vs.push_back(i);
ans.resize(s_s.size(), {-1, -1});
ans.back()={0, 0};
for (ll i=s_s.size()-2; i>=0; i--)
  solve(i);

ans[0].F+=kr[0].F;
ans[0].S+=kr[0].S;
cout<<min(ans[0].F, ans[0].S)<<endl;


if (viv)
  for (auto p:ans)
    cout<<p.F<<' '<<p.S<<endl;





    return 0;
}