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


ll n,i,j, k;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ll ans=0;
ll ubr=n-k;
for (ll i=0; i<n; i++)
  ans+=m[i]*(i+1);
vector <ll> tos;
reverse(m.begin(), m.end());
ll cur=0;
for (ll i=0; i<n-1; i++)
  {
  cur+=m[i];
  tos.push_back(cur);
  }
sort(tos.begin(), tos.end());
for (ll i=0; i<ubr; i++)
  ans-=tos[i];
cout<<ans<<endl;




    return 0;
}