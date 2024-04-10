#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=kk*kk*kk+7;
const long long gs=500*kk;
long n,i,j,r;
long long sum;
vector <long long> m, h;
vector <long> reb[gs+10], dreb[gs+10];
long long col[gs+10];
long long tc[gs+10];
map <long long, long long> mp;
vector <long long> all;


void DFS(long v, long c, long long last)
{
col[v]=c;
if (last!=-1)
  {
  dreb[last].push_back(v);
  dreb[v].push_back(last);
  }

long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1, v);
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
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  h.push_back(0);
  sum+=a;
  }
if (sum!=0)
  {
  cout<<"Impossible";
  return 0;
  }

cin>>r;
for (i=0; i<r; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  mp[ml*a+b]=0;
  all.push_back(ml*a+b);
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

for (i=0; i<n; i++)
  sort(reb[i].begin(), reb[i].end());
for (i=0; i<n; i++)
  col[i]=-1;

DFS(0 ,0, -1);
for (i=0; i<n; i++)
  sort(dreb[i].begin(), dreb[i].end());

vector <pair <long long, long long> > st;
for (i=0; i<n; i++)
  st.push_back({col[i], i});

sort(st.rbegin(), st.rend());

for (i=0; i<n; i++)
  {
  long long v=st[i].second;
  long long l=dreb[v].size();
  for (j=0; j<l; j++)
    {
    long long s=dreb[v][j];
    if (col[s]>col[v])
      {
      long long ost=m[s]-h[s];
      h[s]+=ost;
      h[v]-=ost;
      mp[v*ml+s]=ost;
      mp[s*ml+v]=-ost;
      }
    }
  }
/*
for (i=0; i<n; i++)
  cout<<h[i]<<' ';
cout<<endl;
*/

cout<<"Possible"<<endl;
for (auto i:all)
  cout<<mp[i]<<endl;





    return 0;
}