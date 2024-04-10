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
const ll con=1934993;

ll n,i,j,ans;
string s,t;
vector <ll> z,h;
vector <ll> cod,umn,obrumn;
bool viv=false;
ll kol[2];

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

vector <ll> z_function(const string & s)
{
ll n=s.size();
vector <ll> z(n);
ll l=0, r=0;
for (i=1; i<n; i++)
  {
  if (i<=r)
    z[i]=min(z[i-l], r-i+1);
  while (i+z[i]<n&&s[z[i]]==s[i+z[i]])
    z[i]++;
  if (i+z[i]-1>r)
    l=i, r=i+z[i]-1;
  }
return z;
}

vector <ll> build_hash()
{
srand(time(0));
vector <ll> r;
for (i=0; i<26; i++)
  {
  ll hh=0;
  for (j=0; j<20; j++)
    {
    hh*=10;
    hh+=rand()%10;
    hh%=mod;
    }
  r.push_back(hh);
  }
return r;
}

void build()
{
cod.push_back(0);
for (i=0; i<n; i++)
  {
  cod.push_back(cod.back());
  cod.back()*=con;
  cod.back()+=h[t[i]-'a'];
  cod.back()%=mod;
  }
umn.push_back(1);
for (i=1; i<n; i++)
  {
  umn.push_back(umn.back());
  umn.back()*=con;
  umn.back()%=mod;
  }
}

ll hh(ll a, ll b)
{
ll r=0;
r+=cod[b];
ll v=cod[a];
v*=umn[b-a];
v%=mod;
r-=v;
r%=mod;
r+=mod;
r%=mod;
return r;
}

bool use(ll rl)
{
ll s0=kol[0]*rl;
ll s1=n-s0;
if (s0<=0||s1<=0||(s1%kol[1]!=0))
  return false;
ll l[2];
l[0]=rl;
if (viv)
  cout<<l[0]<<endl;
l[1]=s1/kol[1];
if (viv)
  cout<<l[1]<<endl;
if (viv)
  cout<<"Work "<<l[0]<<' '<<l[1]<<endl;
ll c=0;
vector <ll> st1;
for (j=0; j<s.size(); j++)
  {
  if (viv)
    cout<<c<<endl;
  if (s[j]=='0')
    {
    if (j&&z[c]<l[0])
      return false;
    }
  else
    st1.push_back(c);
  c+=l[s[j]-'0'];
  }
if (viv)
  {
  for (auto i:st1)
    cout<<i<<' ';
  cout<<endl;
  }
ll h=hh(st1[0], st1[0]+l[1]);
if (h==hh(0, l[0]))
  return false;
for (auto i:st1)
  if (hh(i, i+l[1])!=h)
    return false;
return true;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s>>t;
if (s[0]=='1')
  for (auto &i:s)
    if (i=='0')
      i++;
    else
      i--;
for (auto i:s)
  kol[i-'0']++;

n=t.size();
h=build_hash();
build();
z=z_function(t);
if (viv)
  for (i=0; i<n; i++)
    {
    for (j=i; j<n; j++)
      {
      cout<<i<<' '<<j<<' '<<hh(i, j)<<endl;
      }
    }

for (i=1; i<n; i++)
  if (use(i))
    ans++;
cout<<ans;






    return 0;
}