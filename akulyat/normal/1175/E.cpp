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
const ll len=ml/2+10;
const ll L=22;

ll n,i,j, q;
vector <pll> seg, qr;
vector <ll> ans, nex, st;
vector <bool> fl;
set <ll> emp;
vector <vector <ll>> son;
bool viv=false;

bool ins(pll a, pll b)
{
if (a.F<b.F)
  return false;
if (a.S>b.S)
  return false;
return true;
}

void read()
{
cin>>n>>q;
for (i=0; i<n; i++)
  {
  ll a, b;
  cin>>a>>b;
  seg.push_back({a, -b+1});
  }
for (i=0; i<q; i++)
  {
  ll a, b;
  cin>>a>>b;
  qr.push_back({a, b-1});
  }
sort(seg.begin(), seg.end());
vector <pll> rseg;
rseg.push_back({seg[0].F, -seg[0].S});
for (ll i=1; i<n; i++)
  {
  pll pr=seg[i];
  pr.S*=-1;
  if (pr.S>rseg.back().S)
    rseg.push_back(pr);
  }
seg.clear();
seg=rseg;
n=seg.size();
}

void fill()
{
fl.resize(len);
for (ll i=0; i<fl.size(); i++)
  fl[i]=false;
ll las=-mod;
for (auto p:seg)
  {
  ll from=max(las+1, p.F);
  for (ll i=from; i<=p.S; i++)
    fl[i]=true;
  las=max(las, p.S);
  }
for (ll i=0; i<fl.size(); i++)
  if (!fl[i])
    emp.insert(i);
}

void prepare()
{
nex.resize(n, -1);
for (ll i=0; i<n-1; i++)
  {
  ll r=seg[i].S;
  auto z=lower_bound(seg.begin(), seg.end(), make_pair((ll)r+2, (ll)-1))-seg.begin();
  z--;
  if (i<z&&z<n)
    nex[i]=z;
  }
son.resize(L+1);
for (auto &v:son)
  v.resize(n, -1);
son[0]=nex;
for (ll j=0; j<L-1; j++)
  {
  for (ll i=0; i<n; i++)
    if (son[j][i]!=-1)
      son[j+1][i]=son[j][son[j][i]];
  }
st.push_back(1);
for (ll i=0; i<L+3; i++)
  st.push_back(st.back()*2);
}

void check(pll qrs)
{
ll l=qrs.F;
ll r=qrs.S;
  {
  auto z=emp.lower_bound(l);
  if (z!=emp.end()&&(*z)<=r)
    {
    ans.push_back(-1);
    return;
    }
  }
auto now=lower_bound(seg.begin(), seg.end(), make_pair((ll)l, (ll)-1))-seg.begin();
if (now==n||seg[now].F>l)
  now--;
ll lans=1;
if (ins({l, r}, seg[now]))
  {
  ans.push_back(1);
  return;
  }
for (ll loc=L-2; loc>=0; loc--)
  {
  ll jump=son[loc][now];
  //cout<<l<<' '<<r<<' '<<now<<' '<<jump<<endl;
  if (jump!=-1&&seg[jump].S<r)
    lans+=st[loc], now=jump;
  }
lans++;
ans.push_back(lans);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
read();
fill();
prepare();
//viv=true;
if (viv)
  for (auto v:son)
    {
    for (auto i:v)
      cout<<i<<' ';
    cout<<endl;
    }
if (viv)
  {
  cout<<"Segments:";
  for (auto p:seg)
    cout<<'{'<<p.F<<' '<<p.S<<"} ";
  cout<<endl;
  }
for (auto qrs:qr)
  check(qrs);

for (auto i:ans)
  cout<<i<<'\n';






    return 0;
}
/**
2 13
1 3 4 6
0 1
1 2
2 3
3 4
4 5
5 6
6 7
0 2
1 3
2 4
3 5
4 6
5 7

9 7
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

0 1
1 2
9 10
2 5
4 10
1 10
0 10

3 1
1 3
2 5
9 10
1 4


**/