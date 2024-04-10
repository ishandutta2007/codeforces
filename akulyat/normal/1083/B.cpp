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


ll n,i,j,l,k,ans;
vector <ll> m;
bool viv=false;
string s,t;

void cut()
{
while(s.size()&&s.back()==t.back())
  ans++, s.pop_back(), t.pop_back();
}

void work()
{
s.pop_back();
while (s.size())
  {
  if (s.back()=='a')
    m[s.size()]++;
  s.pop_back();
  }
t.pop_back();
while (t.size())
  {
  if (t.back()=='b')
    m[t.size()]++;
  t.pop_back();
  }
ll add=0;
while (m.size())
  {
  m.back()+=add;
  m.back()=min(m.back(), inf/kk);
  ll can=min(m.back(), k);
  k-=can;
  ans+=can*((ll)m.size()-1);
  add+=m.back();
  add=min(add, inf/kk);
  m.pop_back();
//  cout<<ans<<endl;
  }
cout<<ans<<endl;
}

void cases()
{
if (k==1||s.empty())
  {
  cout<<n;
  exit(0);
  }
if (k==2)
  {
  cout<<ans+2*s.size();
  exit(0);
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
cin>>s>>t;
reverse(s.begin(), s.end());
reverse(t.begin(), t.end());
cut();
cases();
m.resize(s.size()+10, 0);
ans+=2*s.size();
k-=2;
work();







    return 0;
}
/*
100 1000000000
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb


*/