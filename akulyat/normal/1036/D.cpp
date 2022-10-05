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


ll n1,n2,i,j;
vector <ll> m1,m2;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n1;
ll s1=0;
ll s2=0;
for (i=0; i<n1; i++)
  {
  ll a;
  cin>>a;
  s1+=a;
  m1.push_back(a);
  }
cin>>n2;
for (i=0; i<n2; i++)
  {
  ll a;
  cin>>a;
  s2+=a;
  m2.push_back(a);
  }
if (s1!=s2)
  {
  cout<<-1;
  return 0;
  }

s1=0;
s2=0;
ll ans=0;
while (m1.size()+m2.size()!=0)
  {
  if (s1<=s2)
    s1+=m1.back(), m1.pop_back();
  else
    s2+=m2.back(), m2.pop_back();
  if (s1==s2)
    {
    ans++;
    s1=0;
    s2=0;
    }
  }

cout<<ans<<endl;















    return 0;
}