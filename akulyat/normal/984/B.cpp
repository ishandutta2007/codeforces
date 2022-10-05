#include <bits/stdc++.h>

using namespace std;


string s[200];
long p[200][200];
long n,m,i,j;


void cc(long x, long y)
{
if (x>=0&&y>=0&&x<n&&y<m)
  p[x][y]++;
}

int main()
{
cin>>n>>m;
getline(cin, s[0]);
for (i=0; i<n; i++)
  {
  getline(cin, s[i]);
  }
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
    if (s[i][j]=='*')
      {
      for (long u=-1; u<2; u++)
        for (long y=-1; y<2; y++)
          cc(i+u, j+y);
      }
    if (s[i][j]=='.')
      s[i][j]='0';
    }
  }
/*
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    cout<<p[i][j];
  cout<<endl;
  }
*/
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    if (s[i][j]<='8'&&s[i][j]>='0')
      if (s[i][j]-'0'!=p[i][j])
        {
        cout<<"NO"<<endl;
        return 0;
        }
  }
cout<<"YES"<<endl;

    return 0;
}