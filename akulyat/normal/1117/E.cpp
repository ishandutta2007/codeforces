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
vector <string> s1, s2;
string s;
bool viv=false;

void build()
{
s1.resize(3);
for (auto &i:s1)
  for (ll j=0; j<n; j++)
    i+='a';
for (ll i=0; i<n; i++)
  {
  ll v=i;
  for (ll j=0; j<3; j++)
    s1[j][i]=char('a'+(v%26)), v/=26;
  }
}

void check()
{
string ans;
for (ll i=0; i<n; i++)
  ans+='a';
for (ll i=0; i<n; i++)
  {
  ll res=0;
  for (ll j=2; j>=0; j--)
    res*=26, res+=(s2[j][i]-'a');
//  cout<<"Let it be "<<s[i]<<" on "<<res<<endl;
  ans[res]=s[i];
  }
cout<<"! "<<ans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n=s.size();
build();
for (auto i:s1)
  {
  cout<<"? "<<i<<endl;
  string str;
  cin>>str;
  s2.push_back(str);
  }
check();








    return 0;
}