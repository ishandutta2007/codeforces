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
vector <bool> same;
string s, t;

void plan_abc()
{
string abc="abc";
string ans;
for (ll i=0; i<n; i++)
  ans+=abc;
cout<<"YES"<<endl;
cout<<ans;
exit(0);
}

void plan_one()
{
if (same[1])
  swap(s, t);
if (s[0]!=t[0]&&s[0]!=t[1])
  {
  string ans;
  for (ll i=0; i<n; i++)
    ans+=t[0],
    ans+=s[0],
    ans+=t[1];
  cout<<"YES"<<endl;
  cout<<ans;
  exit(0);
  }
if (s[0]==t[0])
  t[1]='a'+(0+1+2)-(t[0]-'a')-(t[1]-'a');
else
  t[0]='a'+(0+1+2)-(t[0]-'a')-(t[1]-'a');
ll ost=3-(t[0]-'a')-(t[1]-'a');

string ans;
for (ll i=0; i<n; i++)
  ans+=t;
for (ll i=0; i<n; i++)
  ans+=char('a'+ost);
cout<<"YES"<<endl;
cout<<ans<<endl;
exit(0);
}

void rev(string a, string b)
{
a+=b[1];
reverse(a.begin(), a.end());
string ans;
for (ll i=0; i<n; i++)
  ans+=a;
cout<<"YES"<<endl;
cout<<ans;
exit(0);
}

void plan_dif()
{
vector <bool> have(3, false);
for (auto i:s)
  have[i-'a']=true;
for (auto i:t)
  have[i-'a']=true;
ll kol=0;
for (auto i:have)
  kol+=i;
if (kol==3)
  {
  if (s[1]==t[0])
    rev(s, t);
  if (s[0]==t[1])
    rev(t, s);

  if (s[0]==t[0])
    {
    string ans;
    for (ll i=0; i<n; i++)
      ans+=s[1];
    for (ll i=0; i<n; i++)
      ans+=t[1];
    for (ll i=0; i<n; i++)
      ans+=t[0];
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    exit(0);
    }
  if (s[1]==t[1])
    {
    string ans;
    for (ll i=0; i<n; i++)
      ans+=s[1];
    for (ll i=0; i<n; i++)
      ans+=s[0];
    for (ll i=0; i<n; i++)
      ans+=t[0];
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    exit(0);
    }
  }
  {
  ll ost=3-(s[0]-'a')-(s[1]-'a');
  string ans;
  for (ll i=0; i<n; i++)
    ans+=s[0];
  for (ll i=0; i<n; i++)
    ans+=char('a'+ost);
  for (ll i=0; i<n; i++)
    ans+=s[1];

  cout<<"YES"<<endl;
  cout<<ans;
  exit(0);
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s>>t;
same.push_back(s[0]==s[1]);
same.push_back(t[0]==t[1]);
if (same[0]&&same[1])
  plan_abc();
if (same[0]^same[1])
  plan_one();

plan_dif();





    return 0;
}