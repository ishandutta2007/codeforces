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

long long n,m,q,i,j,len,longest,inp;
vector <long long> reb[gs+10];
vector <long long> w[gs+10];
vector <ll> st,path,road,pp,bra;
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

void DFS1(long long v, long long c, long long l)
{
st.push_back(v);
if (v!=0)
  pp.push_back(l);
col[v]=1;
if (v==n-1)
  len=c, path=st, bra=pp;
long long lr=reb[v].size();
for (long long i=0; i<lr; i++)
  {
  long long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS1(s, c+w[v][i], w[v][i]);
    }
  }
st.pop_back();
pp.pop_back();
}

void DFS(long long v, long long c)
{
col[v]=c;
long long l=reb[v].size();
for (long long i=0; i<l; i++)
  {
  long long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    }
  }
}

void easy()
{
for (ll i=0; i<q; i++)
  cout<<len<<'\n';
exit(0);
}

void add(ll v)
{
longest=max(v, longest);
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q;
m=n-1;
for (i=0; i<m; i++)
  {
  long long a,b,c;
  cin>>a>>b>>c;
  a--; b--;
  reb[a].push_back(b);
  w[a].push_back(c);
  reb[b].push_back(a);
  w[b].push_back(c);
  }
for (i=0; i<n; i++)
  col[i]=-1;
DFS1(0, 0, 0);

for (i=0; i<n; i++)
  road.push_back(false);
for (auto v:path)
  road[v]=true;

for (i=0; i<n; i++)
  {
  ll can=1;
  if (road[i])
    can+=2;
  if (i==n-1||i==0)
    can--;
  if (reb[i].size()>can)
    easy();
  }

inp=inf;
vector <ll> de;
for (i=1; i<bra.size(); i++)
  de.push_back(bra[i]+bra[i-1]);
for (auto v:de)
  inp=min(v, inp);
if (viv)
  cout<<"Shortest pair is "<<inp<<endl;
longest=inf;
longest=len-inp;

for (i=0; i<path.size(); i++)
  {
  ll v=path[i];
  for (j=0; j<reb[v].size(); j++)
    if (!road[reb[v][j]])
      {
      ll s=reb[v][j];
      ll hair=w[v][j];
      if (i!=n-1)
        {
        add(len+hair-bra[i]);
        if (viv)
          cout<<"Offer "<<len+hair-bra[i]<<endl;
        }
      if (i!=0)
        {
        add(len+hair-bra[i-1]);
        if (viv)
          cout<<"Offer "<<len+hair-bra[i-1]<<endl;
        }
      }
  }

vector <ll> sum;
sum.push_back(0);
for (auto v:bra)
  sum.push_back(sum.back()+v);

vector <ll> suf,pref;

for (i=0; i<path.size(); i++)
  {
  ll v=path[i];
  for (j=0; j<reb[v].size(); j++)
    if (!road[reb[v][j]])
      {
      ll s=reb[v][j];
      ll hair=w[v][j];
      pref.push_back(sum[i]+hair);
      suf.push_back(len-sum[i]+hair);
      }
  }

vector <ll> bp;
bp.push_back(-inf);
for (auto i:pref)
  bp.push_back(max(bp.back(), i));
for (i=0; i<suf.size(); i++)
  add(suf[i]+bp[i]);

for (i=0; i<q; i++)
  {
  ll l;
  cin>>l;
  cout<<min(longest+l, len)<<'\n';
  }

if (viv)
  {
  cout<<"Path from first to last==";
  for (auto v:path)
    cout<<v<<' ';
  cout<<endl;
  cout<<"Edges from first to last==";
  for (auto v:bra)
    cout<<v<<' ';
  cout<<endl;
  cout<<"Length from first to i==";
  for (auto v:sum)
    cout<<v<<' ';
  cout<<endl;
  cout<<"Length from first to i-st least==";
  for (auto v:pref)
    cout<<v<<' ';
  cout<<endl;
  cout<<"Best length from first to i-st least==";
  for (auto v:bp)
    cout<<v<<' ';
  cout<<endl;
  }






    return 0;
}