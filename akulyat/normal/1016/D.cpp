#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j,m;
vector <ll> a,b;
bool viv=false;
ll p[kk][kk];

int main()
{
cin>>n>>m;
ll ax=0;
ll bx=0;
for (i=0; i<n; i++)
  {
  ll v;
  cin>>v;
  a.push_back(v);
  ax^=v;
  }
for (i=0; i<m; i++)
  {
  ll v;
  cin>>v;
  b.push_back(v);
  bx^=v;
  }

if (ax!=bx)
  {
  cout<<"NO";
  return 0;
  }
cout<<"YES"<<endl;
for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    {
    if (j==m-1&&i!=n-1)
      p[i][j]=a[i];
    if (i==n-1&&j!=m-1)
      p[i][j]=b[j];
    }
  }

ll r=0;
for (i=0; i<n-1; i++)
  r^=a[i];
p[n-1][m-1]=r^b[j-1];

for (i=0; i<n; i++)
  {
  for (j=0; j<m; j++)
    cout<<p[i][j]<<' ';
  cout<<endl;
  }





    return 0;
}