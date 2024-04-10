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

ll xs, x, ys, y;
ll tox, toy, help, need, step, ma;
ll n,i,j;
ll ans,kol;
vector <ll> m;
string s;
map <char, ll> mean;
bool viv=false;

void bad()
{
cout<<-1<<endl;
exit(0);
}

bool check(ll kol)
{
ll was=kol*n;
ll pox=tox*kol;
ll poy=toy*kol;
for (ll i=0; i<n; i++)
  {
  if (s[i]=='L'||s[i]=='R')
    pox+=mean[s[i]];
  else
    poy+=mean[s[i]];
  if (abs(pox-x)+abs(poy-y)-was-i-1<=0)
    return true;
  }
return false;

}

bool norm(ll d)
{
ll was=d;
ll kol=d/n;
d%=n;
if (kol&&check(kol-1))
  return true;
ll pox=tox*kol;
ll poy=toy*kol;
for (ll i=0; i<d; i++)
  {
  if (s[i]=='L'||s[i]=='R')
    pox+=mean[s[i]];
  else
    poy+=mean[s[i]];
  if (abs(pox-x)+abs(poy-y)-kol*n-i-1<=0)
    return true;
  }
return false;
}

ll solve()
{
ll l=0;
ll r=1;
while (!norm(r))
  {
  r<<=1;
  if (r>inf/4)
    bad();
  }
while (l+1<r)
  {
  if (viv)
    cout<<l<<' '<<r<<endl;
  ll mi=l+r>>1;
  if (norm(mi))
    r=mi;
  else
    l=mi;
  }
return r;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>xs>>ys;
cin>>x>>y;
x-=xs;
y-=ys;
cin>>n;
cin>>s;
mean['L']=-1;
mean['R']=1;
mean['D']=-1;
mean['U']=1;

if (x<0)
  {
  x=abs(x);
  mean['L']*=-1;
  mean['R']*=-1;
  }
if (y<0)
  {
  y=abs(y);
  mean['D']*=-1;
  mean['U']*=-1;
  }

for (ll i=0; i<n; i++)
  {
  if (s[i]=='L'||s[i]=='R')
    tox+=mean[s[i]];
  else
    toy+=mean[s[i]];
  }
cout<<solve();







    return 0;
}