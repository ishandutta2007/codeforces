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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ll> m;
bool viv=false;
string s;

void solve1()
{
ll j1=0;
while (s[j1]==s[0])
  j1++;
reverse(s.begin(), s.end());
ll j2=0;
while (s[j2]==s[0])
  j2++;
ll ans=0;
if (s[0]==s.back())
  ans=(j1+1)*(j2+1);
else
  ans=j1+j2+1;
ans%=mod;
cout<<ans;
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
solve1();












    return 0;
}