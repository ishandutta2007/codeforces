#include <iostream>

using namespace std;

long pos[1000][1000];
long i,j,n,m;


int main()
{
cin>>n>>m;
for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    {
    char sy; cin>>sy;
    if (sy=='S')
      pos[i][j]=1;
    if (sy=='W')
      pos[i][j]=-1;
    }
for (i=0; i<n; i++)
  for (j=0; j<m-1; j++)
    {
    long a,b;
    a=pos[i][j];
    b=pos[i][j+1];
    if ((a+b==0)&&(a*b!=0))
      {
      cout<<"No";
      return 0;
      }
    }
for (i=0; i<n-1; i++)
  for (j=0; j<m; j++)
    {
    long a,b;
    a=pos[i][j];
    b=pos[i+1][j];
    if ((a+b==0)&&(a*b!=0))
      {
      cout<<"No";
      return 0;
      }
    }

cout<<"Yes"<<endl;
for (i=0; i<n; i++)
  {
  for (j=0;  j<m; j++)
    {
    if (pos[i][j]==1)
      cout<<'S';
    if (pos[i][j]==-1)
      cout<<'W';
    if (pos[i][j]==0)
      cout<<'D';
    }
  cout<<endl;
  }
    return 0;
}