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
string s;

void bad()
{
cout<<-1<<endl;
exit(0);
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n=s.size();
while (s.back()!=']'&&s.size())
  s.pop_back();
if (s.size()<2)
  bad();
s.pop_back();
reverse(s.begin(), s.end());
while (s.back()!='['&&s.size())
  s.pop_back();
if (s.size()<2)
  bad();
s.pop_back();
reverse(s.begin(), s.end());

while (s.back()!=':'&&s.size())
  s.pop_back();
if (s.size()<2)
  bad();
s.pop_back();
reverse(s.begin(), s.end());
while (s.back()!=':'&&s.size())
  s.pop_back();
if (s.size()<1)
  bad();
s.pop_back();
reverse(s.begin(), s.end());
ll kol=0;
//cout<<s<<endl;
for (ll i=0; i<s.size(); i++)
  if (s[i]!='|')
      kol++;
ll ans=n-s.size()-4+kol;
ans=n-ans;
cout<<ans<<endl;







    return 0;
}