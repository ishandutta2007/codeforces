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
vector <ll> m,kol;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll sum=0;
m.push_back(0);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  ll b=0;
  while (a)
    b+=a&1, a/=2;
  kol.push_back(b);
  sum+=(b&1);
  m.push_back(sum&1);
  }


ll a=0;
ll b=0;
ll ans=0;
for (i=0; i<=n; i++)
  {
  if (m[i])
    ans+=a, a++;
  else
    ans+=b, b++;
  if (i>0&&m[i]==m[i-1])
    ans--;
  }
//viv=true;
if (viv)
  cout<<ans<<endl;
for (i=0; i<n; i++)
  {
  ll want=kol[i];
  vector <ll> s1[2];
  ll z=0;
  for (j=i+1; j<=min(i+61, n-1); j++)
    z+=kol[j], s1[z&1].push_back(z);
  vector <ll> s2[2];
  z=0;
  for (j=i-1; j>=max(i-61, 0ll); j--)
    z+=kol[j], s2[z&1].push_back(z);
  s1[0].push_back(0);
  s2[0].push_back(0);
  sort(s1[0].begin(), s1[0].end());
  sort(s2[0].begin(), s2[0].end());
  sort(s1[1].begin(), s1[1].end());
  sort(s2[1].begin(), s2[1].end());
  if (viv)
    {
    for (auto j:s1[0])
      cout<<j<<' ';
    cout<<endl;
    for (auto j:s1[1])
      cout<<j<<' ';
    cout<<endl;
    for (auto j:s2[0])
      cout<<j<<' ';
    cout<<endl;
    for (auto j:s2[1])
      cout<<j<<' ';
    cout<<endl;
    }
  for (auto v:s1[0])
    {
    ll ost=want-v;
    ll t=ost&1;
    ans-=(upper_bound(s2[t].begin(), s2[t].end(), ost-1)-s2[t].begin());
//    cout<<"Change "<<ost<<' '<<(upper_bound(s2[t].begin(), s2[t].end(), ost)-s2[t].begin())<<endl;
    }

  for (auto v:s1[1])
    {
    ll ost=want-v;
    ll t=ost&1;
    ans-=(upper_bound(s2[t].begin(), s2[t].end(), ost-1)-s2[t].begin());
//    cout<<"Change "<<ost<<' '<<(upper_bound(s2[t].begin(), s2[t].end(), ost)-s2[t].begin())<<endl;
    }
  if (!(want&1))
    ans++/*, cout<<"add "<<i<<'\n'*/;
  }

cout<<ans<<endl;
if (viv)
  for (auto i:kol)
    cout<<i<<' ';


    return 0;
}