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


ll n,i,j,k;
vector <ll> m;
bool viv=false;
set <ll> fre;
set <pll> have;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  have.insert({a, i});
  }

for (i=0; i<k; i++)
  fre.insert(n+i);

ll ans=0;
ll cou=0;
vector <ll> it;
for (i=0; i<n; i++)
  it.push_back(i);
while (*fre.rbegin()!=k-1)
  {
  ll now=*fre.rbegin();
  while ((*have.begin()).S>now)
    have.erase(have.begin());
  pll z=*have.begin();
  have.erase(*have.begin());
//  cout<<"____ "<<now<<' '<<z.F<<' '<<z.S<<endl;

  ans+=z.F*(now-z.S);
  it[z.S]=now;
  fre.erase(*fre.rbegin());
  fre.insert(z.S);
  }

cout<<ans<<endl;
for (auto i:it)
  cout<<i+1<<' ';
cout<<endl;




    return 0;
}