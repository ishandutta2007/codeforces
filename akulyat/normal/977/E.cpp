#include <bits/stdc++.h>

using namespace std;

const long z=500000;
long n,m,tc,i,j,u;
vector <long> reb[z];
long long col[z];
bool zd[z];
vector <long long> colv;

void DFS(long v)
{
col[v]=tc;
long k=reb[v].size();
for (long i=0; i<k; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    DFS(s);
  }

}


int main()
{
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

for (i=0; i<n; i++)
  col[i]=-1;

tc=0;
for (i=0; i<n; i++)
  if (col[i]==-1)
    {
    DFS(i);
    tc++;
    }


for (i=0; i<tc; i++)
  zd[i]=true;

// /*
for (i=0; i<n; i++)
  if (reb[i].size()!=2)
    {
    zd[col[i]]=false;
    //cout<<"bad is "<<i+1<<endl;
    }
// */

long ans=0;
for (i=0; i<tc; i++)
  if (zd[i])
    ans++;

cout<<ans<<endl;

/*
for (i=0; i<n; i++)
  cout<<col[i]<<' ';
cout<<endl;
*/



    return 0;
}