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
const long long inf=5*ml*ml*ml+7;


ll n,i,j,x,y;
vector <pll> m;
set <pll> s;
multiset <ll> fr;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>x>>y;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b+1});
//  s.insert({a, b+1});
  }
sort(m.begin(), m.end());
ll ans=0;
for (auto p:m)
  {
  ll p1=x+(p.S-p.F-1)*y;
  ll p2=inf;
  auto x=fr.upper_bound(p.F);
  if (x!=fr.begin())
    {
    x--;
    ll last=(*x);
//    cout<<"Use "<<last<<"? "<<p.S<<endl;
    fr.erase(x);
    p2=(p.S-last)*y;
    }
  ans+=(min(p2, p1)%mod);
  ans%=mod;
//  cout<<ans<<endl;
  fr.insert(p.S);
//  cout<<"add "<<p.S<<endl;
  }
cout<<ans;











    return 0;
}