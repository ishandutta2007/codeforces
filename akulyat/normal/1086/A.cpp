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
vector <pll> x;
bool viv=false;
map <pll, bool> was;
pair<ll, string> ans;

string ll_to_str(long long v)
{
string s="";
if (v==0)
  return "0";
bool obr=false;
if (v<0)
  obr=true;
v=abs(v);
while (v>0)
  {
  short e=v%10;
  s+=char('0'+e);
  v/=10;
  }
reverse(s.begin(), s.end());
if (obr)
  s='-'+s;
return s;
}

void write(pll a)
{
if (was[a])
  return;
was[a]=true;
ans.F++;
ans.S+=ll_to_str(a.F);
ans.S+=' ';
ans.S+=ll_to_str(a.S);
ans.S+='\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
x.assign(3, {0, 0});
for (ll i=0; i<3; i++)
  cin>>x[i].F>>x[i].S;
sort(x.begin(), x.end());
pll cur=x[0];
while (cur.F<x[1].F)
  {
  write(cur);
  cur.F++;
  }
while (cur.S<x[1].S)
  {
  write(cur);
  cur.S++;
  }
while (cur.S>x[1].S)
  {
  write(cur);
  cur.S--;
  }
while (cur.S<x[2].S)
  {
  write(cur);
  cur.S++;
  }
while (cur.S>x[2].S)
  {
  write(cur);
  cur.S--;
  }
while (cur.F<x[2].F)
  {
  write(cur);
  cur.F++;
  }
write(cur);
cout<<ans.F<<endl;
cout<<ans.S<<endl;






    return 0;
}