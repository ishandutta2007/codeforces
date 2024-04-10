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
vector <ll> m,l;
bool viv=false;
map <char, ll> mp;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
string s;
cin>>s;
mp['G']=1;
mp['S']=0;
for (auto i:s)
  m.push_back(mp[i]);
m.push_back(0);
ll h=0;
for (i=0; i<n+1; i++)
  {
  l.push_back(h);
  if (!m[i])
    l.back()=0, h=0;
  else
    l.back()++, h++;
  }
ll kol=0;
for (auto i:l)
  if (i==1)
    kol++;
if (kol==0)
  {
  cout<<0<<endl;
  return 0;
  }
ll ans=*max_element(l.begin(), l.end());
if (kol>1)
  ans++;
for (i=n-1; i>=0; i--)
  if (l[i]&&l[i+1])
    l[i]=l[i+1];
ll mp=0;
for (i=1; i<n; i++)
  if (!l[i])
    mp=max(mp, l[i-1]+l[i+1]);
if (kol>2)
  mp++;
ans=max(ans, mp);
cout<<ans<<endl;




    return 0;
}