#include <iostream>

using namespace std;

long long n,m,i,j;
long long pol[100][100];
long long a[100];
string s;
int main()
{
cin>>n>>m;
getline(cin, s);
for (i=0; i<n; i++)
  {
  getline(cin, s);
  for (j=0; j<m; j++)
    if (s[j]=='#')
      pol[i][j]=1;
  }
for (i=0; i<n; i++)
  {
  a[i]=0;
  for (j=0; j<m; j++)
    {
    a[i]*=2;
    a[i]+=pol[i][j];
    }
  }
//for (i=0; i<n; i++)
//  cout<<a[i]<<endl;
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    {
    //cout<<i<<' '<<j<<' '<<(a[i]^a[j])<<' '<<(a[i]&a[j])<<endl;
    if (((a[i]^a[j])!=0)&&((a[i]&a[j])!=0))
      {
      cout<<"No";
      return 0;
      }
    }
cout<<"Yes";

    return 0;
}