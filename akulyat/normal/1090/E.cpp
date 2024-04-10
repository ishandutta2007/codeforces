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
vector <pll> mp;
vector <pair <pll, pll> > ans;
map <pll, vector <pll> > fr;
bool p[8][8];
bool viv=false;


void read()
{
cin>>n;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  ll y=s[1]-'1';
  ll x=s[0]-'a';
  p[y][x]=true;
  }
}

void build_friend()
{
for (ll i=0; i<8; i++)
  for (ll j=0; j<8; j++)
    for (ll ii=0; ii<8; ii++)
      for (ll jj=0; jj<8; jj++)
        if (abs(ii-i)&&abs(jj-j)&&abs(jj-j)+abs(ii-i)==3)
          fr[{i, j}].push_back({ii, jj});
if (viv)
  for (ll i=0; i<8; i++)
    for (ll j=0; j<8; j++)
      {
      cout<<i<<' '<<j<<'_';
      for (auto p:fr[{i, j}])
        cout<<p.F<<' '<<p.S<<' ';
      cout<<endl;
      }
}

void show()
{
if (!viv)
  return;
for (ll i=7; i>=0; i--)
  {
  for (ll j=0; j<8; j++)
    cout<<char('0'+p[i][j]);
  cout<<endl;
  }
cout<<"________________"<<endl;
}

void BFS(pll star)
{
if (viv)
  cout<<star.F<<' '<<star.S<<endl;
mp.clear();
if (p[star.F][star.S])
  {
  mp={{star.F, star.S}};
  return;
  }
ll col[8][8];
vector <pll> path[8][8];
for (ll i=0; i<8; i++)
  for (ll j=0; j<8; j++)
    col[i][j]=inf;
col[star.F][star.S]=0;
vector <pll> st;
st.push_back(star);
ll s=0;
while (s<st.size())
  {
  pll v=st[s];
  for (auto sos:fr[v])
    if (col[sos.F][sos.S]==inf)
      {
      path[sos.F][sos.S]=path[v.F][v.S];
      path[sos.F][sos.S].push_back(v);
      col[sos.F][sos.S]=0;
      st.push_back(sos);
      if (sos.F*8+sos.S>star.F*8+star.S&&p[sos.F][sos.S])
        {
        path[sos.F][sos.S].push_back(sos);
        mp=path[sos.F][sos.S];
        return;
        }
      }
  if (viv)
    {
    for (auto p:st)
      cout<<p.F<<'_'<<p.S<<' ';
    cout<<endl;
    }
  s++;
  }
}

void swap(pll l, pll n)
{
ans.push_back({l, n});
p[l.F][l.S]=false;
p[n.F][n.S]=true;
//show();
}

void  work (ll num)
{
ll x=num/8;
ll y=num%8;
BFS({x, y});
reverse(mp.begin(), mp.end());
if (viv)
  {
  cout<<"Swapper ";
  for (auto p:mp)
    cout<<p.F<<'_'<<p.S<<' ';
  cout<<endl;
  }
while (mp.size())
  {
  ll j=mp.size()-1;
  while (j>=0&&!p[mp[j].F][mp[j].S])
    j--;
  if (j<0)
    return;
  for (ll u=j; u<(ll)mp.size()-1; u++)
    swap(mp[u], mp[u+1]);
  mp.pop_back();
  }



}

void write()
{
cout<<ans.size()<<endl;
for (auto pp:ans)
  {
  pll a=pp.F;
  pll b=pp.S;
  cout<<char(a.S+'a');
  cout<<char(a.F+'1');
  cout<<'-';
  cout<<char(b.S+'a');
  cout<<char(b.F+'1');
  cout<<endl;
  }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
read();
build_friend();
show();
for (ll i=0; i<n; i++)
  work(i);
write();
show();
    return 0;
}