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


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll l,x;
cin>>n>>l>>x;
m.push_back(0);
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  b+=a;
  m.push_back(a);
  m.push_back(b);
  }
m.push_back(l);
ll ans=0;
for (i=0; i<2*n+2; i++)
  if (!(i&1))
    ans+=(m[i+1]-m[i])/x;
cout<<ans<<endl;




    return 0;
}