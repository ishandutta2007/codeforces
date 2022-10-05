#include <bits/stdc++.h>

using namespace std;


int main()
{
//    cout << "Hello world!" << endl;
long long n,m,i,j,u;
const long long ccc=500000; //#@$%@$#%$@%#$@%#$@%$#@%#
vector <long long> reb[ccc],tic[ccc];
long long pro[ccc],num[ccc],ans[ccc];
set <pair<long long, long long> > tos;

vector <long long> por;
cin>>n>>m;
for (i=0; i<m; i++)
  {
  long long a,b,c;
  cin>>a>>b>>c;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  tic[a].push_back(c);
  tic[b].push_back(c);
  }
/*
for (i=0; i<n; i++)
  {
  for (j=0; j<reb[i].size(); j++)
    cout<<i<<' '<<reb[i][j]<<' '<<' '<<tic[i][j]<<' ';
  cout<<endl;
  }
cout<<endl;
*/

for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  pro[i]=a; ans[i]=a;
  pair <long long, long long> d;
  d.first=a;
  d.second=i;
  tos.insert(d);
  }
/*
for (set <pair<long long, long long> >::const_iterator ui=tos.begin(); ui!=tos.end(); ui++)
  cout<<(*ui).first<<' '<<(*ui).second<<' '<<endl;
*/
while (tos.size()>0)
  {
  j=(*tos.begin()).second;
  for (u=0; u<reb[j].size(); u++)
    {
    if (ans[j]+tic[j][u]*2<ans[reb[j][u]])
      {
      pair <long long, long long> d;
      d.second=reb[j][u];
      d.first=ans[reb[j][u]];
      tos.erase(d);
      d.first=ans[j]+tic[j][u]*2;
      tos.insert(d);
      ans[reb[j][u]]=ans[j]+tic[j][u]*2;
//      cout<<d.first<<' '<<reb[j][u];
 //     return 0;
      }
    }
  pair <long long, long long> d;
  d.second=j;
  d.first=ans[j];
  tos.erase(d);
//  cout<<tos.size();
  }

for (i=0; i<n; i++)
  cout<<ans[i]<<' ';


   return 0;
}