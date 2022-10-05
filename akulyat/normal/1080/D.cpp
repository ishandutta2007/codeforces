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
vector <ll> m,kol,use;
bool viv=false;

void solve()
{
ll s,k;
cin>>s>>k;
if (s>kol.size())
  {
  cout<<"YES ";
  cout<<s-1<<endl;
  return;
  }
ll work=0;
for (i=0; i<=s; i++)
  {
  work+=use[i];
  ll ost=k-work;
  if (ost>=0&&ost<=kol[s]-work-kol[s-i]*use[i+1])
    {
    cout<<"YES ";
    cout<<s-i<<endl;
    return;
    }
  }
cout<<"NO"<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
kol.push_back(0);
while (kol.back()<4*inf)
  kol.push_back(kol.back()*4+1);
use.push_back(0);
for (auto i:kol)
  use.push_back(use.back()*2+1);

/*
for (auto i:kol)
  cout<<i<<' ';
cout<<endl;
*/
for (i=0; i<30; i++)
while (t)
  {
  solve();
  t--;
  }

    return 0;
}