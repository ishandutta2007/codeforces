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


ll n,i,j;
vector <ll> m;
bool viv=false;

void solve()
{
cin>>n;
ll kol[3]={0, 0, 0};
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a%=3;
  kol[a]++;
  }
ll ans=0;
ans+=kol[0];
ll mi=min(kol[1], kol[2]);
ans+=mi;
kol[1]-=mi;
kol[2]-=mi;
ans+=kol[1]/3;
ans+=kol[2]/3;
cout<<ans<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t)
  solve(), t--;



    return 0;
}