#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long    ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=998244353;
const long long inf=ml*ml*ml+7;
const long long L=200;

ll n,i,j;
vector <ll> m;
bool viv=false;
ll dpg[10][L+3];
ll dpb[10][L+3];
ll sumg[10][L+3];
ll sumb[10][L+3];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m.push_back(0);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
m.push_back(0);
dpg[0][0]=1;
sumg[0][0]=1;
for (i=1; i<=L; i++)
  sumg[0][i]=1;
ll t=0;
for (i=1; i<=n; i++)
  {
  t^=1;
  for (j=0; j<=L; j++)
    dpb[t][j]=0,
    dpg[t][j]=0,
    sumb[t][j]=0,
    sumg[t][j]=0;

  for (j=1; j<=L; j++)
    {
    sumb[t][j]=sumb[t][j-1];
    sumg[t][j]=sumg[t][j-1];

    dpb[t][j]+=sumg[t^1][j-1];
    dpb[t][j]+=sumb[t^1][j-1];
    dpg[t][j]+=sumg[t^1][L]-sumg[t^1][j-1];
    dpg[t][j]+=dpb[t^1][j];
    dpb[t][j]%=mod;
    dpg[t][j]%=mod;
    if (m[i]!=j&&m[i]+1)
      dpb[t][j]=0, dpg[t][j]=0;
//    cout<<i<<' '<<j<<' '<<dpg[i][j]<<' '<<dpb[i][j]<<endl;
    sumb[t][j]+=dpb[t][j];
    sumg[t][j]+=dpg[t][j];
    sumb[t][j]%=mod;
    sumg[t][j]%=mod;
    }
  }
cout<<(sumg[t][L]+mod)%mod;






    return 0;
}