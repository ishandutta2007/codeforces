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
const long long gs=500*kk*2;

long n,m,i,j,kol;
vector <long> reb[gs+10];
vector <long> edge[gs+10];
vector <long> rreb[gs+10];
vector <long> redge[gs+10];
vector <ll> ist,st;
map <ll, ll> num;
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

void DFS(long v, long start)
{
if (reb[v].empty())
  edge[num[start]].push_back(num[v]),
  redge[num[v]].push_back(num[start]);
col[v]=1;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, start);
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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  rreb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;

for (i=0; i<n; i++)
  if (reb[i].empty())
    kol++, st.push_back(i);
for (i=0; i<n; i++)
  if (rreb[i].empty())
    ist.push_back(i);
for (i=0; i<kol; i++)
  num[ist[i]]=i;
for (i=0; i<kol; i++)
  num[st[i]]=kol+i;

/*
cout<<kol<<endl;
for (auto v:ist)
  cout<<v<<' ';
cout<<endl;
for (auto v:st)
  cout<<v<<' ';
cout<<endl;
*/




for (auto v:ist)
  {
  for (i=0; i<n; i++)
    col[i]=-1;
  DFS(v, v);
  }

for (ll bits=1; bits<(1ll<<kol)-1; bits++)
  {
  vector <bool> use;
  ll mask=bits;
  ll k1=0, k2=0;
  for (i=0; i<kol; i++)
    use.push_back(mask&1), k1+=use.back(), mask/=2;
  vector <bool> they(kol, 0);
  for (ll v=0; v<kol; v++)
    if (use[v])
      for (auto s:edge[v])
        they[s-kol]=true;
  for (auto v:they)
    k2+=v;

  bool komp=true;
  if (k2>k1)
    komp=false;
  if (komp)
    {
    cout<<"NO"<<endl;;
    return 0;
    }

  }
cout<<"YES"<<endl;


    return 0;
}