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
const long long gs=300*kk;

long n,m,i,j;
ll p[gs][22];
vector <long> reb[gs+10];
vector <ll> col,tc,ans,st,num,vich;
bool viv=false;


void BFS(long v)
{
st.push_back(v);
long s=0;
tc[v]=0;

while (s<st.size())
  {
  long e=st[s];
  long l=reb[e].size();
  for (long i=0; i<l; i++)
    {
    long sos=reb[e][i];
    if (tc[sos]==-1)
      {
      p[st.size()][0]=s;
      col[st.size()]=col[s]+1;
      st.push_back(sos);
      tc[sos]=tc[e]+1;
      }
    }
  s++;
  }
for (j=1; j<20; j++)
  {
  for (i=0; i<n; i++)
    p[i][j]=p[p[i][j-1]][j-1];
  }
num.resize(n);
for (i=0; i<n; i++)
  num[st[i]]=i;
}

ll par(ll v, ll up)
{
ll cur=v;
ll add=1<<20;
for (ll j=20; j>=0; j--)
  {
  if (add<=up)
    {
    cur=p[cur][j];
    up-=add;
    }
  add>>=1;
  }
return cur;
}

void seg(ll v, ll d, ll x)
{
v=num[v];
ll l=v;
ll r=n;
if (viv)
  cout<<"I try find level "<<d<<" for "<<v<<endl;
  {
  ll r=n;
  while (l+1<r)
    {
    ll mi=l+r>>1;
    if (col[mi]<col[v]+d||(col[mi]==col[v]+d&&par(mi, col[mi]-col[v])<v))
      l=mi;
    else
      r=mi;
    }
  l++;
  }
  {
  ll l=v;
  while (l+1<r)
    {
    ll mi=l+r>>1;
    if (col[mi]>col[v]+d||(col[mi]==col[v]+d&&par(mi, col[mi]-col[v])>v))
      r=mi;
    else
      l=mi;
    }
  r--;
  }
if (viv)
  cout<<"Level "<<d<<" for "<<v<<" is segment "<<l<<' '<<r<<endl;
vich[l]-=x;
vich[r+1]+=x;
}

void work()
{
ll q;
vich.resize(n+1);
ans.assign(n, 0);
cin>>q;
while (q)
  {
  ll v,d,x;
  cin>>v>>d>>x; v--;
  ans[v]+=x;
  seg(v, d+1, x);
  q--;
  }
ll sum=0;

for (ll i=0; i<n; i++)
  {
  sum+=vich[i];
  ans[st[i]]+=sum;
  if (viv)
    cout<<i<<' '<<ans[i]<<endl;
  }
}

void write()
{
for (ll i=0; i<n; i++)
  cout<<ans[i]<<' ';
cout<<endl;
}

void push(ll v)
{
for (auto s:reb[v])
  if (tc[s]>tc[v])
    {
    ans[s]+=ans[v];
    push(s);
    }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m=n-1;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
col.assign(n, -1);
tc.assign(n, -1);
ans.assign(n, -1);
BFS(0);
work();
push(0);
write();

    return 0;
}