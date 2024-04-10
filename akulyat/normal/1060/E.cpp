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

long long n,m,i,j,ans;
vector <ll> kol[2],sum[2];
vector <long> reb[gs+10];
long long col[gs+10];
long long tc[gs+10];
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    }
  }
}

void work (ll v)
{
vector <ll> kids;
for (auto s:reb[v])
  if (col[s]>col[v])
    kids.push_back(s);
for (auto s:kids)
  {
  kol[0][v]+=kol[1][s];
  kol[1][v]+=kol[0][s];
  kol[1][v]++;
  sum[0][v]+=sum[1][s];
  sum[0][v]+=kol[1][s];
  sum[1][v]+=sum[0][s];
  sum[1][v]+=kol[0][s]+1;
  }
ll lans=0;
ll nn=0;
for (auto s:kids)
  {
  ll k0=kol[1][s];
  ll k1=kol[0][s]+1;
  ll s0=sum[1][s]+k0;
  ll s1=sum[0][s]+k1;
  if (viv)
    cout<<v<<" and "<<s<<' '<<k0<<' '<<s0<<' '<<k1<<' '<<s1<<endl;
  lans+=(s0/2)*(kol[0][v]+kol[1][v]-k0-k1);
  lans+=((s1+k1)/2)*(kol[0][v]+kol[1][v]-k0-k1);
  nn+=k1*(kol[1][v]-k1);
  }
nn/=2;
lans-=nn;
if (viv)
  cout<<"Answer "<<nn<<' '<<lans<<' ';
lans+=sum[0][v]/2;
lans+=(sum[1][v]+kol[1][v])/2;
ans+=lans;
if (viv)
  cout<<v<<' '<<lans<<endl;
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
for (i=0; i<n; i++)
  col[i]=-1;
DFS(0, 0);
vector <pll> tos;
for (i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> por;
for (auto i:tos)
  por.push_back(i.S);

for (i=0; i<n; i++)
  for (j=0; j<2; j++)
    kol[j].push_back(0),
    sum[j].push_back(0);

for (auto i:por)
  work(i);
cout<<ans<<endl;
if (viv)
  for (ll v=0; v<n; v++)
    {
    cout<<v<<':'<<endl;
    cout<<kol[0][v]<<' ';
    cout<<sum[0][v]<<endl;
    cout<<kol[1][v]<<' ';
    cout<<sum[1][v]<<endl;
    }





    return 0;
}