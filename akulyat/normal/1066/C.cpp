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


ll n,i,j,add,wl;
vector <ll> m,was,sum,type,bef;
bool viv=false;

void build()
{
for (i=0; i<ml; i++)
  was.push_back(-1);
for (i=0; i<ml; i++)
  type.push_back(-1);
for (i=0; i<ml; i++)
  bef.push_back(-1);
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
build();
for (i=0; i<n; i++)
  {
  string s;
  ll a;
  cin>>s>>a;
  a--;
  if (s!="?")
    {
    was[a]=i;
    bef[a]=add;
    type[a]= (s=="L") ? 0 : 1;
    wl+= (s=="L")? 1 : 0;
    sum.push_back(wl);
    add++;
    }
  else
    {
    sum.push_back(sum.back());
    ll tol=0;
    if (type[a])
      tol+=bef[a];
    tol+=wl-sum[was[a]];
    cout<<min(tol, add-tol-1)<<'\n';
    }
  }











    return 0;
}