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
map <char, vector<ll> > mp;
map <char, ll> kol;
ll x,y;
string s;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
for (i=0; i<n; i++)
  mp[s[i]].push_back(i);
cin>>x>>y;
if (abs(x)+abs(y)>n||((x+y-n)&1))
  {
  cout<<-1;
  return 0;
  }
ll tol=max(0ll, (ll)mp['R'].size()-(ll)mp['L'].size()-x);
ll tor=max(0ll, x-((ll)mp['R'].size()-(ll)mp['L'].size()));
ll tod=max(0ll, (ll)mp['U'].size()-(ll)mp['D'].size()-y);
ll tou=max(0ll, y-((ll)mp['U'].size()-(ll)mp['D'].size()));
//cout<<tol<<' '<<tor<<' '<<tod<<' '<<tou<<endl;
if (tol==0&&tor==0&&tod==0&&tou==0)
  {
  cout<<0;
  return 0;
  }


ll l=0;
ll r=n;
while (l+1<r)
  {
  ll m=l+r>>1;
  ll v=0;
  bool good=false;
  kol['R']=mp['R'].size();
  kol['L']=mp['L'].size();
  kol['U']=mp['U'].size();
  kol['D']=mp['D'].size();
  for (i=0; i<m; i++)
    kol[s[i]]--;
  while (v+m<=n)
    {
    if (v)
      kol[s[v-1]]++,
      kol[s[v+m-1]]--;
    ll lx=kol['R']-kol['L'];
    ll ly=kol['U']-kol['D'];
//    cout<<v<<' '<<v+m-1<<' '<<lx<<' '<<ly<<endl;
    if (abs(lx-x)+abs(ly-y)<=m)
      good=true;
    v++;
    }
  if (good)
    r=m;
  else
    l=m;

  }

cout<<r<<endl;






    return 0;
}