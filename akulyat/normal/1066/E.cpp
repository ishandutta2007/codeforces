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


ll n,i,j,ans;
vector <ll> m;
bool viv=false;
string s,t;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll a,b;
cin>>a>>b;
cin>>s>>t;
reverse(s.begin(), s.end());
reverse(t.begin(), t.end());
while (s.size()<t.size())
  s+='0';
while (t.size()<s.size())
  t+='0';
n=s.size();
ll kol=0;
for (i=0; i<n; i++)
  if (t[i]-'0')
    kol++;
ll st=1;
ll ans=0;
for (i=0; i<n; i++)
  {
  if (s[i]-'0')
    ans+=st*kol;
  ans%=mod;
  st*=2;
  st%=mod;
  if (t[i]-'0')
    kol--;
  }
cout<<ans;




    return 0;
}