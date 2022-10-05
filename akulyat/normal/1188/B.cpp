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


ll n,i,j, p, k;
vector <ll> m;
bool viv=false;

ll func(ll val)
{
ll res=1;
res*=val; res%=p;
res*=val; res%=p;
res*=val; res%=p;
res*=val; res%=p;
res-=val*k;
res%=p;
if (res<0)
  res+=p;
return res;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>p>>k;
vector <ll> f;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  f.push_back(func(a));
  }
sort(f.begin(), f.end());
vector <ll> rep(n+1, 1);
for (ll i=1; i<n; i++)
  if (f[i]==f[i-1])
    rep[i]+=rep[i-1];
ll ans=0;
for (ll i=0; i<n; i++)
  if (rep[i+1]==1)
    ans+=rep[i]*(rep[i]-1)/2;
cout<<ans<<endl;


    return 0;
}
/**

aaaa-bbbb=k(a-b)
bbbb-bk=aaaa-ak






**/