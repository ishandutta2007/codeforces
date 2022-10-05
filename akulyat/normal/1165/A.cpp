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
ll l, x, y;
string s;
cin>>l>>x>>y;
cin>>s;
for (auto i:s)
  m.push_back(i-'0');
reverse(m.begin(), m.end());
while (m.size()>x)
  m.pop_back();
m[y]^=1;
ll ans=0;
for (auto i:m)
  ans+=i;
cout<<ans<<endl;



    return 0;
}