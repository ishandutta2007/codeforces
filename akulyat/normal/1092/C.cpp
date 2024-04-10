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
vector <pair<pair <ll, string>, ll> > m;
bool viv=false;
string full;

void easy()
{
string ans;
for (ll i=0; i<n*2-2; i++)
  ans+='0';
set <ll> was;
for (auto i:m)
  {
  ll len=i.F.F;
  ll pl=i.S;
  if (was.count(len))
    ans[pl]='S';
  else
    ans[pl]='P';
  was.insert(len);
  }
cout<<ans<<endl;
exit(0);
}

void work(string full)
{
string ans;
for (ll i=0; i<n*2-2; i++)
  ans+='0';
set <ll> was;
string rfull=full;
reverse(rfull.begin(), rfull.end());
for (auto i:m)
  {
  ll len=i.F.F;
  ll pl=i.S;
  string t=i.F.S;
  string rt=i.F.S;
  reverse(rt.begin(), rt.end());
  bool b1=false;
  bool b2=false;
  if (full.substr(0, len)==t)
    b1=true;
  if (rfull.substr(0, len)==rt)
    b2=true;
  if (b1)
    ans[pl]='P';
  if (b2)
    ans[pl]='S';
  if (b1&&b2)
    {
    if (was.count(len))
      ans[pl]='P';
    else
      ans[pl]='S';
    }
  was.insert(len);
  }
for (auto i:ans)
  if (i=='0')
    return;
cout<<ans<<endl;
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<2*n-2; i++)
  {
  string a;
  cin>>a;
  ll l=a.size();
  m.push_back({{l, a}, i});
  }
sort(m.begin(), m.end());
work(m[2*n-4].F.S[0]+m[2*n-3].F.S);
work(m[2*n-3].F.S[0]+m[2*n-4].F.S);





    return 0;
}