#include <bits/stdc++.h>

using namespace std;

long long n,m,k,i,j,u,hour;
vector <long long> have[2000],uber[2000],ans[2000];
vector <long long> bok2[2000],bok1[2000];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k;
for (i=0; i<n; i++)
  {
  string ss;
  cin>>ss;
  for (j=0; j<m; j++)
    if (ss[j]=='1')
      have[i].push_back(j);
  }

for (i=0; i<n; i++)
  {
  long long l=have[i].size();
  bok1[i].push_back(0);
  bok2[i].push_back(0);
  for (j=1; j<l; j++)
    {
    bok1[i].push_back(have[i][j]-have[i][0]);
    bok2[i].push_back(have[i][l-1]-have[i][l-j-1]);
    }
  bok1[i].push_back(0);
  bok2[i].push_back(0);
  if (l!=0)
    {
    bok1[i].back()=have[i].back()-have[i][0]+1;
    bok2[i].back()=have[i].back()-have[i][0]+1;
    hour+=bok1[i].back();
    }
  for (j=bok1[i].size(); j<=k; j++)
    bok1[i].push_back(bok1[i].back());
  for (j=bok2[i].size(); j<=k; j++)
    bok2[i].push_back(bok2[i].back());
  }

for (i=0; i<n; i++)
  {
  for (j=0; j<have[i].size(); j++)
    {
    uber[i].push_back(0);
    for (u=0; u<=j; u++)
      uber[i].back()=max(uber[i].back(), bok1[i][u]+bok2[i][j-u]);
    }
  uber[i].push_back(bok1[i][have[i].size()]);
  for (j=have[i].size()+1; j<=k; j++)
    uber[i].push_back(uber[i].back());
  }
for (i=0; i<=k; i++)
  ans[0].push_back(uber[0][i]);

for (i=1; i<n; i++)
  for (j=0; j<=k; j++)
    {
      ans[i].push_back(0);
    for (u=0; u<=j; u++)
      ans[i].back()=max(ans[i].back(), ans[i-1][u]+uber[i][j-u]);
    }
/*
for (i=0; i<n; i++)
  {
  for (auto j:have[i])
    cout<<j<<' ';
  cout<<endl;
  }
cout<<endl;
for (i=0; i<n; i++)
  {
  for (auto j:uber[i])
    cout<<j<<' ';
  cout<<endl;
  }
cout<<endl;

for (i=0; i<n; i++)
  {
  for (auto j:ans[i])
    cout<<j<<' ';
  cout<<endl;
  }
cout<<endl;
*/

cout<<hour-ans[n-1][k];

    return 0;
}