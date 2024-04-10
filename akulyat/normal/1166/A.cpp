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
vector <ll> l(26, 0);
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  l[s[0]-'a']++;
  }
ll ans=0;
for (auto v:l)
  {
  ll a=v/2;
  ll b=v-a;
  ans+=(a*(a-1))/2;
  ans+=(b*(b-1))/2;
  }
cout<<ans<<endl;


    return 0;
}