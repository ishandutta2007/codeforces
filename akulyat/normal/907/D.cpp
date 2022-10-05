#include <bits/stdc++.h>

using namespace std;


long long n,m,i,j;
vector <long long> ans[300000];

int main()
{
cin>>n>>m;


if (n==3&&m==3)
  {
  cout<<"YES"<<endl;
  cout<<"5 7 3"<<endl;
  cout<<"9 1 8"<<endl;
  cout<<"2 6 4"<<endl;
  return 0;
  }

if (n==1&&m==1)
  {
  cout<<"YES"<<endl;
  cout<<"1"<<endl;
  return 0;
  }


if (m>=4)
  {
  cout<<"YES"<<endl;
  vector <long long> v;
  if (m==4)
    v={2, 4, 1, 3};
  else
    {
    for (i=0; i<m; i++)
      if ((i^1)&1)
        v.push_back(i+1);
    for (i=0; i<m; i++)
      if ((i)&1)
        v.push_back(i+1);
    }
  if (m&1)
    {
    for (i=0; i<n; i++)
      {
      long long s=i*m;
      for (j=0; j<m; j++)
        cout<<s+v[(j+(i&1))%m]<<' ';
      cout<<'\n';
      }
    }
  else
    {
    for (i=0; i<n; i++)
      {
      long long s=i*m;
      for (j=0; j<m; j++)
        cout<<s+v[j+(i&1)*(m-1-j-j)]<<' ';
      cout<<'\n';
      }
    }

  return 0;
  }

if (n>=4)
  {
  cout<<"YES"<<endl;
  vector <long long> v;
  if (n==4)
    v={m+1, 3*m+1, 0*m+1, 2*m+1};
  else
    {
    for (i=0; i<n; i++)
      if ((i^1)&1)
        v.push_back(i*m+1);
    for (i=0; i<n; i++)
      if ((i)&1)
        v.push_back(i*m+1);
    }
  if (n&1)
    {
    for (i=0; i<m; i++)
      {
      long long s=i;
      for (j=0; j<n; j++)
        ans[j].push_back(s+v[(j+(i&1))%n]);
//      cout<<'\n';
      }
    }
  else
    {
    for (i=0; i<m; i++)
      {
      long long s=i;
      for (j=0; j<n; j++)
        ans[j].push_back(s+v[j+(i&1)*(n-1-j-j)]);
//      cout<<'\n';
      }
    }
  for (i=0; i<n; i++)
    {
    for (j=0; j<m; j++)
      cout<<ans[i][j]<<' ';
    cout<<'\n';
    }


  return 0;

  }

cout<<"NO"<<endl;




    return 0;
}

// 5 7 3
// 9 1 8
// 2 6 4