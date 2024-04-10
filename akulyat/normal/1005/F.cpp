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
const long long gs=500*kk;
long long n,m,i,j,k;
vector <long> reb[gs+10];
vector <long> num[gs+10];
vector <long> fri[gs+10];
long long col[gs+10];
long long tc[gs+10];
vector <ll> var;
map <ll, ll> mp;


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
cin>>n>>m>>k;
for (i=0; i<m; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  mp[a*mod+b]=i;
  mp[b*mod+a]=i;
  num[a].push_back(i);
  num[b].push_back(i);
  }
for (i=0; i<n; i++)
  col[i]=-1;

for (i=0; i<n; i++)
  tc[i]=-1;

BFS(0);

var.push_back(1);
ll have=1;
for (i=1; i<n; i++)
  {
  var.push_back(0);
  ll l=reb[i].size();
  for (ll j=0; j<l; j++)
    {
    ll s=reb[i][j];
    if (tc[s]+1==tc[i]&&(var.back()==0||have<k*10))
      {
      var.back()++;
      fri[i].push_back(s);
      }
    }
  have*=var[i];
  }
/*
for (i=0; i<n; i++)
  {
  cout<<i<<": ";
  for (auto j:fri[i])
    cout<<j<<' ';
  cout<<endl;
  }
*/
ll rk=1;
for (auto i:var)
  {
  rk*=i;
  if (rk>k)
    rk=k;
  }
k=rk;

vector <ll> iw;
for (i=0; i<n; i++)
  iw.push_back(0);

cout<<k<<endl;
while (k>0)
  {
  vector <ll> ch;
  for (i=0; i<m; i++)
    ch.push_back(0);
//  cout<<"Ost "<<k<<endl;
  for (i=1; i<n; i++)
    {
    ll s=fri[i][iw[i]];
//    cout<<"Use "<<i<<' '<<s<<' ';
    ch[mp[s*mod+i]]=1;
//    cout<<" OK ";
    }
//  cout<<endl;
  for (auto i:ch)
    cout<<i;
  cout<<endl;
  k--;
  iw[n-1]++;
  for (i=n-1; i>0; i--)
    {
    iw[i-1]+=(iw[i]/var[i]);
    iw[i]%=var[i];
    }
  }





    return 0;
}