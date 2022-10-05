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


ll n,n1,i,j;
vector <ll> m;
bool viv=false;
string s,t;

int main()
{
cin>>n>>n1;
cin>>s>>t;
ll k=0;
for (i=0; i<n; i++)
  if (s[i]=='*')
    k=1;
if (!k)
  {
  if (s==t)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
  }

while (t.size()>0&&s.back()==t.back())
  s.pop_back(), t.pop_back();
reverse(s.begin(), s.end());
reverse(t.begin(), t.end());
while (t.size()>0&&s.back()==t.back())
  s.pop_back(), t.pop_back();

if (s.size()==1)
  cout<<"YES";
else
  cout<<"NO";





    return 0;
}