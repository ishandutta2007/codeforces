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


ll n,i,j,ost;
vector <ll> m;
bool viv=false;
bool demo=false;

bool have(ll v)
{
ost--;
cout<<"> "<<v-1<<endl;
ll ans;
cin>>ans;
return ans;
}

ll ask(ll pl)
{
ost--;
cout<<"? "<<pl+1<<endl;
ll val;
cin>>val;
return val;
}

ll last()
{
ll l=0;
ll r=mod-6;
if (demo)
  r=40;
while (l+1!=r)
  {
  ll mi=l+r>>1;
  if (have(mi))
    l=mi;
  else
    r=mi;
  }
return l;
}

long long GCD(long long a, long long b)
{
if (a==0&&b==0)
  return 1;
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}

int main()
{
//demo=true;
srand(time(0));
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ost=60;
if (demo)
  ost=10;
ll ma=last();
m.push_back(ma);
while (ost)
  {
  ll pl=(rand()*1000+rand()*100+rand()*10+rand())%n;
  ll val=ask(pl);
  m.push_back(val);
  }
vector <ll> v;
for (auto i:m)
  for (auto j:m)
    if (i-j)
      v.push_back(abs(i-j));
ll d=v[0];
for (auto i:v)
  d=GCD(i, d);
ll a=ma-d*(n-1);
cout<<"! "<<a<<' '<<d<<endl;







    return 0;
}