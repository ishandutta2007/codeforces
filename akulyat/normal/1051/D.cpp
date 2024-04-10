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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ll> m;
bool viv=false;
long long p[2*kk][4*kk][4];


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll k;
cin>>n>>k;
p[1][1][0]=1;
p[1][1][3]=1;
p[1][2][1]=1;
p[1][2][2]=1;

for (i=2; i<=n; i++)
  {
  for (j=1; j<3000; j++)
    {
    p[i][j][0]+=p[i-1][j][0];
    p[i][j][0]+=p[i-1][j][1];
    p[i][j][0]+=p[i-1][j][2];
    p[i][j][0]+=p[i-1][j-1][3];
    p[i][j][3]+=p[i-1][j-1][0];
    p[i][j][3]+=p[i-1][j][1];
    p[i][j][3]+=p[i-1][j][2];
    p[i][j][3]+=p[i-1][j][3];

    p[i][j][1]+=p[i-1][j-1][0];
    p[i][j][1]+=p[i-1][j][1];
    p[i][j][1]+=p[i-1][j-2][2];
    p[i][j][1]+=p[i-1][j-1][3];
    p[i][j][2]+=p[i-1][j-1][0];
    p[i][j][2]+=p[i-1][j-2][1];
    p[i][j][2]+=p[i-1][j][2];
    p[i][j][2]+=p[i-1][j-1][3];

    for (ll u=0; u<4; u++)
      p[i][j][u]%=mod;
    }
  }

cout<<(p[n][k][0]+p[n][k][1]+p[n][k][2]+p[n][k][3])%mod;









    return 0;
}