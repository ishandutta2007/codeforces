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
const long long gs=500*kk;

long n,m,i,j;
vector <long> reb[gs+10];
vector <long> rreb[gs+10];
vector <ll> p;
ll price;
long long col[gs+10];
long long last[gs+10];
long long tc[gs+10];
bool viv=false;

ll DFS1(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    return DFS1(s, c);
    }
  else
    return v;
  }
}

void full(long v, long c)
{
last[v]=c;
long l=rreb[v].size();
for (long i=0; i<l; i++)
  {
  long s=rreb[v][i];
  if (last[s]==-1)
    {
    full(s, c);
    }
  }
}





void BFS(long v)
{
vector <long> st;
st.push_back(v);
long s=0;
tc[v]=0;

while (s<st.size())
  {
  long e=st[s];
  long l=reb[e].size();
  for (long i=0; i<l; i++)
    {
    long s=reb[e][i];
    if (tc[s]==-1)
      {
      st.push_back(s);
      tc[s]=tc[e]+1;
      }
    }
  s++;
  }

}


int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  p.push_back(a);
  }
for (i=0; i<n; i++)
  {
  long a,b;
  cin>>b;
  a=i;
  b--;
  reb[a].push_back(b);
  rreb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;
for (i=0; i<n; i++)
  last[i]=-1;

ll tc=0;
ll ans=0;
for (i=0; i<n; i++)
  if (last[i]==-1)
    {
    ll llast=DFS1(i, tc);
    ll price=inf;
    ll s=llast;
    while (reb[s][0]!=llast)
      price=min(price, p[s]), s=reb[s][0];
    price=min(price, p[s]), s=reb[s][0];
    full(llast, llast);
    ans+=price;
//    cout<<i<<' '<<ans<<endl;
    }

cout<<ans<<endl;










    return 0;
}