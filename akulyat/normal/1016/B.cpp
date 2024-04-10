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
const long long mod2=1533503;
const long long mod3=1530019;
const long long inf=ml*ml*ml+7;


ll n,i,j,l,q,z;
vector <ll> h,rav;
vector <string> m;
bool viv=false;
string s,t;


vector <ll> build_hash()
{
srand(time(0));
vector <ll> r;
for (i=0; i<26; i++)
  {
  ll hh=0;
  for (j=0; j<20; j++)
    {
    hh*=10;
    hh+=rand()%10;
    hh%=mod;
    }
  r.push_back(hh);
  }
return r;
}


int main()
{
cin>>n>>l>>q;
cin>>s>>t;

//h=build_hash();

for (i=0; i<n-l+1; i++)
  {
  string ss;
  for (ll j=0; j<l; j++)
    ss+=s[i+j];
  m.push_back(ss);
  }
ll kol=0;
rav.push_back(kol);
for (auto i:m)
  {
  if (i==t)
    kol++;
  rav.push_back(kol);
  }
for (i=0; i<1010; i++)
  rav.push_back(rav.back());
/*
for (auto i:rav)
  cout<<i<<' ';
cout<<endl;
for (auto i:m)
  cout<<i<<' ';
cout<<endl;
*/

for (ll u=0; u<q; u++)
  {
  ll lg,rg;
  cin>>lg>>rg;
  lg--;
  rg-=l;
  rg++;
  rg=max(rg, lg);
//  cout<<lg<<' '<<rg<<' ';
  cout<<rav[rg]-rav[lg]<<endl;
  }








    return 0;
}