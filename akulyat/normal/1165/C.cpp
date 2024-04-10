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
cin>>n;
string s;
cin>>s;
string t;
for (ll i=0; i<n; i++)
  {
  if (!(t.size()&1)||t.back()!=s[i])
    t+=s[i];
  }
if (t.size()&1)
  t.pop_back();


cout<<n-t.size()<<endl;
cout<<t<<endl;

    return 0;
}