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


ll n,i,j,step;
vector <ll> m[2];
vector <ll> z[2];
vector <ll> sum;
bool viv=false;

void add()
{
step++;
if (((i^j)^1)&1)
  i^=1;
else
  j++;
}


int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m[0].push_back(a);
  z[0].push_back(0);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m[1].push_back(a);
  z[1].push_back(0);
  }

ll ss=0;
sum.push_back(0);
for (i=n-1; i>=0; i--)
  {
  ss+=m[0][i];
  ss+=m[1][i];
  sum.push_back(ss);
  }
reverse(sum.begin(), sum.end());
/*
for (auto i:sum)
  cout<<i<<' ';
cout<<endl;
*/



z[0][n-1]=m[1][n-1];
z[1][n-1]=m[0][n-1];
for (i=n-2; i>=0; i--)
  {
  z[0][i]=z[0][i+1];
  z[0][i]+=sum[i+1];
  z[0][i]+=m[1][i]*(2*(n-1-i)+1);
  z[1][i]=z[1][i+1];
  z[1][i]+=sum[i+1];
  z[1][i]+=m[0][i]*(2*(n-1-i)+1);
  }
/*
for (auto i:z[0])
  cout<<i<<' ';
cout<<endl;
for (auto i:z[1])
  cout<<i<<' ';
cout<<endl;
*/


i=0;
j=0;
ll sobr=0;
step=0;
ll ans=0;
while (j<n)
  {
//  cout<<i<<' '<<j<<endl;
  if (((i^j)^1)&1)
    {
    ans=max(ans, sobr+z[i][j]+sum[j]*step);
    }
  sobr+=m[i][j]*step;
  add();
  }

cout<<ans<<endl;




    return 0;
}