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

string res(string s)
{
string da="YES";
string net="NO";
if (s.size()<11)
  return net;
for (ll i=0; i<10; i++)
  s.pop_back();
for (auto i:s)
  if (i=='8')
    return da;
return net;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll k;
  cin>>k;
  string a;
  cin>>a;
  cout<<res(a)<<endl;
  }


    return 0;
}