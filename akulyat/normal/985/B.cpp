#include <iostream>

using namespace std;


long n,m,i,j;
long p[3000][3000];
long kol[3000];
string s;
int main()
{
cin>>n>>m;
getline(cin, s);
for (i=0; i<n; i++)
  {
  getline(cin, s);
  for (j=0; j<m; j++)
    {
    p[i][j]=(s[j]-'0');
    if (p[i][j]==1)
      kol[j]++;
    }
  }
for (i=0; i<n; i++)
  {
  bool good=true;
  for (j=0; j<m; j++)
    if (p[i][j]==1&&kol[j]==1)
      good=false;
  if (good)
    {
    cout<<"YES";
    return 0;
    }
  }
cout<<"NO";
    return 0;
}