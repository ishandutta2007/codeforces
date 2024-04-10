#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <ll> m;
string s;

int main()
{
cin>>s;
n=s.size();
m.push_back(0);
for (i=0; i<n; i++)
  m.push_back(m.back()+s[i]-'0');

vector <ll> ans;
ans.push_back(0);

for (i=0; i<n; i++)
  {
  ans.push_back(ans[i]);
  ll cs=0;
  for (ll j=i; j>=max(i-4, 0ll); j--)
    {
    cs+=s[j];
    if (cs%3==0)
      ans[i+1]=max(ans[i+1], ans[j]+1);
    }
  }



cout<<ans[n];






    return 0;
}