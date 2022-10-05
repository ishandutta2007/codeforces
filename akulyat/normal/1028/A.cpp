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


ll n,m,i,j;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
ll sx=n;
ll bx=-1;
ll sy=m;
ll by=-1;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  for (j=0; j<m; j++)
    if (s[j]=='B')
      {
      sy=min(sy, j);
      by=max(by, j);
      sx=min(sx, i);
      bx=max(bx, i);
      }

  }

cout<<(sx+bx)/2+1<<' '<<(sy+by)/2+1<<endl;



    return 0;
}