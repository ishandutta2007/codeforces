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
vector <ll> v;
bool viv=false;
ll kol[2000];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<m; i++)
  v.push_back (((i+1)*(i+1))%m);
ll full=n/m;
for (auto i:v)
  kol[i]+=full;
n%=m;
for (i=0; i<n; i++)
  kol[v[i]]++;
ll ans=0;
for (i=0; i<m; i++)
  ans+=kol[i]*kol[(m-i)%m];
cout<<ans<<endl;












    return 0;
}