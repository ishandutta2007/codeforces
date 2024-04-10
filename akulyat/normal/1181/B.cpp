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
string ans;

bool more(string a, string b)
{
if (a.size()>b.size())
  return true;
if (a.size()<b.size())
  return false;
for (ll i=0; i<a.size(); i++)
  {
  if (a[i]>b[i])
    return true;
  if (a[i]<b[i])
    return false;
  }
return false;
}

void check(string new_ans)
{
if (viv)
  cout<<"Cmp "<<ans<<" and "<<new_ans<<" ";
if (more(ans, new_ans))
  ans=new_ans;
if (viv)
  cout<<" and now is "<<ans<<endl;
}

string sum(string a, string b)
{
if (viv)
  cout<<"Sum of "<<a<<" and "<<b<<" is ";
reverse(a.begin(), a.end());
reverse(b.begin(), b.end());
while (a.size()<b.size())
  a+='0';
while (b.size()<a.size())
  b+='0';
a+='0';
b+='0';
ll n=a.size();
for (ll i=0; i<n; i++)
  {
  ll c=0;
  c+=(a[i]-'0');
  c+=(b[i]-'0');
  if (c>9)
    a[i+1]++,
    c-=10;
  a[i]=char('0'+c);
  }
while (a.back()=='0'&&a.size()>1)
  a.pop_back();
reverse(a.begin(), a.end());
if (viv)
  cout<<a<<endl;
return a;
}

void solve1(ll pl)
{
while (pl<s.size()&&s[pl]=='0')
  pl++;
if (pl>=s.size()||pl<0)
  return;
string a=s.substr(0, pl);
string b=s.substr(pl, s.size()-pl);
if (b.size()==0||a.size()==0)
  return;
if (b[0]=='0')
  return;
string c=sum(a, b);
check(c);
}

void solve2(ll pl)
{
while (pl>=0&&s[pl]=='0')
  pl--;
if (pl>=s.size()||pl<0)
  return;
string a=s.substr(0, pl);
string b=s.substr(pl, s.size()-pl);
if (b.size()==0||a.size()==0)
  return;
if (b[0]=='0')
  return;
string c=sum(a, b);
check(c);
}


int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
ll pl=s.size()/2;
ans="";
for (ll i=0; i<ml/5; i++)
  ans+='1';
for (ll i=-10; i<=10; i++)
  solve1(pl+i),
  solve2(pl+i);
cout<<ans<<endl;






    return 0;
}