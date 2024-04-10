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


ll n,k,i,j,ans;
vector <pll> m;
vector <ll> ob;
bool viv=false;

long long obr(long long v, long long mod)
{
long long i=0;
long long st=mod-2;
vector <long long> bin;
long long l=0;
while(st>0)
  {
  bin.push_back(st&1);
  st/=2;
  l++;
  }

vector <long long> sq;
sq.push_back(v);
for (i=1; i<l; i++)
  {
  long long s=sq.back();
  s*=s;
  s%=mod;
  sq.push_back(s);
  }

long long ans=1;
for (i=0; i<l; i++)
  if (bin[i])
    {
    ans*=sq[i];
    ans%=mod;
    }
return ans;
}


void prepare(ll n)
{
ll n1=n;
for (ll i=2; i<floor(sqrt(n))+2; i++)
  if (i*i<=n&&!(n1%i))
    {
    m.push_back({i, 0});
    while (!(n1%i))
      n1/=i, m.back().S++;
    }
if (n1!=1)
  m.push_back({n1, 1});
for (ll i=0; i<100; i++)
  ob.push_back(i);
for (ll i=1; i<100; i++)
  ob[i]=obr(ob[i], mod);
}

void work(ll v)
{
vector <ll> s;
s.assign(m[v].S, 0);
s.push_back(1);
for (ll i=0; i<k; i++)
  {
  vector <ll> ws;
  ws.assign(s.size(), 0);
  ll sum=0;
  for (j=s.size()-1; j>=0; j--)
    {
    ll ver=s[j];
    ver*=ob[j+1];
    sum+=ver;
    sum%=mod;
    ws[j]=sum;
    }
  s=ws;
  }
ll cur=1;
ll lans=0;
for (ll i=0; i<=m[v].S; i++)
  {
  s[i]*=cur;
  s[i]%=mod;
  lans+=s[i];
  lans%=mod;
  cur*=m[v].F;
  cur%=mod;
  }
ans*=lans;
ans%=mod;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
 /*
n=1;
n*=64;
n*=81;
n*=25;
n*=49;
n*=11;
n*=13;
n*=17;
n*=19;
n*=23;
n*=29;
cout<<n<<endl;
cout<<7*5*3*3*2*64<<endl;
// */
prepare(n);
//for (auto p:m)
//  cout<<p.F<<' '<<p.S<<endl;
ans=1;
for (ll i=0; i<m.size(); i++)
  work(i);
cout<<ans<<endl;









    return 0;
}