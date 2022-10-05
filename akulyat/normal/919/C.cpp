#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long  n,m,k,ans=0,i,j;
vector <long> zan[10000];
cin>>n>>m>>k;
string st,s[10000];
getline(cin, st);
for (i=0; i<n; i++)
  getline(cin, s[i]);
for (i=0; i<n; i++)
  {
  zan[i].push_back(-1);
  for (j=0; j<m; j++)
    if (s[i][j]=='*')
      {
      zan[i].push_back(j);
     // cout<<"dob "<<j<<endl;
      }
  zan[i].push_back(m);
  }
for (i=0; i<n; i++)
  {
  for (j=0; j<(long)zan[i].size()-1; j++)
    {ans+=max(zan[i][j+1]-zan[i][j]-k, (long)0);
//    cout<<zan[i][j+1]<<' '<<zan[i][j]<<endl;
    }
  zan[i].clear();
  }
for (j=0; j<m; j++)
  {
  zan[j].push_back(-1);
  for (i=0; i<n; i++)
    if (s[i][j]=='*')
      zan[j].push_back(i);
  zan[j].push_back(n);
  }
for (j=0; j<m; j++)
  {
  for (i=0; i<(long)zan[j].size()-1; i++)
    {ans+=max(zan[j][i+1]-zan[j][i]-k, (long)0);
//  cout<<zan[j][i+1]<<' '<<zan[j][i]<<endl;
    }
  }
if (k==1)
  cout<<ans/2; else
    cout<<ans;




















    return 0;
}