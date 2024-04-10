#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=200;
const long long N=110;

struct mine
{
  ll x,y,num,was,st,ch,f;
};


ll n,i,j;
vector <ll> m;
vector <ll> t;
vector <mine> st;
bool viv=false;
pll p[N][N][3];
pll pos[N][N][3];


void build()
{
for (ll i=0; i<110; i++)
  for (ll j=0; j<110; j++)
    for (ll u=0; u<3; u++)
      p[i][j][u]={inf, inf},
      pos[i][j][u]={inf, inf};
}

void DFS(mine km)
{
ll x=km.x;
ll y=km.y;
ll num=km.num;
ll was=km.was;
ll step=km.st;
ll ch=km.ch;
ll f=km.f;
if (x<0||x>=n)
  return;
if (y<0||y>=n)
  return;
if (num==was+1)
  was++;
if (p[num][was][f]<=(pll){step, ch})
  return;
if (pos[num][was][f]<=(pll){step, ch})
  return;
pos[num][was][f]=min(pos[num][was][f], (pll){step, ch});
st.push_back(km);
}

void work(mine km)
{
ll x=km.x;
ll y=km.y;
ll num=km.num;
ll was=km.was;
ll st=km.st;
ll ch=km.ch;
ll f=km.f;
if (x<0||x>=n||y<0||y>=n)
  return;
if (num==was+1)
  was++;
if (p[num][was][f]<=(pll){st, ch})
  return;
p[num][was][f]={st, ch};
pos[num][was][f]={st, ch};
if (was==n*n)
  return;
for (ll i=0; i<n; i++)
  {
  ll nf=0;
  ll nst=st+(f!=nf);
  ll nch=ch+(f!=nf);
  ll pl1=i*n+y;
  ll pl2=x*n+i;
  DFS({i, y, t[pl1], was, nst+1, nch, nf});
  DFS({x, i, t[pl2], was, nst+1, nch, nf});
  }
for (ll i=0; i<n; i++)
  {
  ll nf=1;
  ll nst=st+(f!=nf);
  ll nch=ch+(f!=nf);
  ll pl1=(x+i)*n+(y+i);
  ll pl2=(x+i)*n+(y-i);
  ll pl3=(x-i)*n+(y+i);
  ll pl4=(x-i)*n+(y-i);
  DFS({(x+i), (y+i), t[pl1], was, nst+1, nch, nf});
  DFS({(x+i), (y-i), t[pl2], was, nst+1, nch, nf});
  DFS({(x-i), (y+i), t[pl3], was, nst+1, nch, nf});
  DFS({(x-i), (y-i), t[pl4], was, nst+1, nch, nf});
  }
  {
  ll nf=2;
  ll nst=st+(f!=nf);
  ll nch=ch+(f!=nf);
  ll pl1=(x+1)*n+(y+2);
  ll pl2=(x+1)*n+(y-2);
  ll pl3=(x-1)*n+(y+2);
  ll pl4=(x-1)*n+(y-2);
  ll pl5=(x+2)*n+(y+1);
  ll pl6=(x+2)*n+(y-1);
  ll pl7=(x-2)*n+(y+1);
  ll pl8=(x-2)*n+(y-1);
    DFS({(x+1), (y+2), t[pl1], was, nst+1, nch, nf});
    DFS({(x+1), (y-2), t[pl2], was, nst+1, nch, nf});
    DFS({(x-1), (y+2), t[pl3], was, nst+1, nch, nf});
    DFS({(x-1), (y-2), t[pl4], was, nst+1, nch, nf});
    DFS({(x+2), (y+1), t[pl5], was, nst+1, nch, nf});
    DFS({(x+2), (y-1), t[pl6], was, nst+1, nch, nf});
    DFS({(x-2), (y+1), t[pl7], was, nst+1, nch, nf});
    DFS({(x-2), (y-1), t[pl8], was, nst+1, nch, nf});
  }





}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m.resize(n*n);
t.resize(n*n);
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    {
    ll a;
    cin>>a;
    a--;
    m[a]=i*n+j;
    t[i*n+j]=a;
    }
build();
DFS({m[0]/n, m[0]%n, 0, -1, 0, 0, 0});
DFS({m[0]/n, m[0]%n, 0, -1, 0, 0, 1});
DFS({m[0]/n, m[0]%n, 0, -1, 0, 0, 2});
ll s=0;
while (s!=st.size())
  work(st[s]), s++;


ll a,b;
a=p[n*n-1][n*n-1][0].F;
b=p[n*n-1][n*n-1][0].S;
if ((pll){a, b}>p[n*n-1][n*n-1][1])
  a=p[n*n-1][n*n-1][1].F,
  b=p[n*n-1][n*n-1][1].S;
if ((pll){a, b}>p[n*n-1][n*n-1][2])
  a=p[n*n-1][n*n-1][2].F,
  b=p[n*n-1][n*n-1][2].S;

cout<<a<<' '<<b<<endl;
 /*
for (i=0; i<n*n; i++)
  {
  for (j=0; j<n*n; j++)
    {
    cout<<"{ ";
    cout<<p[i][j][0].F<<' ';
    cout<<p[i][j][0].S<<' ';
    cout<<p[i][j][1].F<<' ';
    cout<<p[i][j][1].S<<' ';
    cout<<p[i][j][2].F<<' ';
    cout<<p[i][j][2].S;
    cout<<" }";
    }
  cout<<endl;
  }
 */







    return 0;
}