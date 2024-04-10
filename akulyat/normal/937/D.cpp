#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;
const long long gs=500*kk;
long n,m,i,j,s;
vector <long> reb[gs+10];
long long col[2][gs+10];
bool draw=false;
vector <long long> path;
bool block[gs+10], now[gs+10];
set <long long> sreb[gs+10];

void DFS(long v, long c)
{
path.push_back(v);
col[c&1][v]=c;
now[v]=true;
long l=reb[v].size();
if ((path.size()&1)==0&&l==0)
  {
  cout<<"Win"<<endl;
  for (auto i:path)
    cout<<i+1<<' ';
  exit(0);
  }
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (now[s])
    draw=true;
  if (col[(c+1)&1][s]==-1)
    DFS(s, c+1);
  }
now[v]=false;
path.pop_back();
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<n; i++)
  {
  long long l;
  cin>>l;
  for (j=0; j<l; j++)
    {
    long b;
    cin>>b;
    b--;
    sreb[i].insert(b);
    }
  }
for (i=0; i<n; i++)
  for (auto j:sreb[i])
    reb[i].push_back(j);
cin>>s;
s--;

for (i=0; i<n; i++)
  {
  col[0][i]=-1;
  col[1][i]=-1;
  }

DFS(s, 0);

if (draw)
  {
  cout<<"Draw"<<endl;
  return 0;
  }

cout<<"Lose"<<endl;







    return 0;
}