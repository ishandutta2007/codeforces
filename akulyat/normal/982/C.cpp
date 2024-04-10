#include <bits/stdc++.h>

using namespace std;

const long kk=100*1000;
long n,i,j;
vector <long> reb[2*kk];
long ver[2*kk];
long col[2*kk];
long sum[2*kk];

long DFS(long v)
{
col[v]=1;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==0)
    {
    sum[v]+=DFS(s);
    ver[v]+=ver[s];
    }
  }
ver[v]++;
if (ver[v]%2==0)
  sum[v]++;
//cout<<v<<' '<<sum[v]<<' '<<ver[v]<<endl;
return sum[v];

}


int main()
{
long n;
cin>>n;
for (i=0; i<n-1; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

if (n%2==1)
  {
  cout<<-1;
  return 0;
  }


cout<<DFS(0)-1<<endl;
//for (i=0; i<n; i++)
//  cout<<ver[i]<<' ';



    return 0;
}