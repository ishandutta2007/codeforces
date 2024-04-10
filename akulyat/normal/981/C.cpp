#include <bits/stdc++.h>

using namespace std;

const long kk=100*1000;
long n,i;
long fr;
vector <long> reb[2*kk];
long col[2*kk];
vector <long> ans;


void DFS(long v)
{
col[v]=1;

long l=reb[v].size();
if (l==1&&v!=fr)
  ans.push_back(v);
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==0)
    DFS(s);
  }
}


int main()
{
cin>>n;
for (i=0; i<n-1; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

long ms=0;
for (i=0; i<n; i++)
  if (reb[i].size()>ms)
  {
  ms=reb[i].size();
  fr=i;
  }
for (i=0; i<n; i++)
  if (i!=fr&&reb[i].size()>2)
    {
    cout<<"No";
    return 0;
    }

DFS(fr);

cout<<"Yes"<<endl;
cout<<ans.size()<<endl;
for (i=0; i<ans.size(); i++)
  cout<<fr+1<<' '<<ans[i]+1<<endl;
    return 0;
}