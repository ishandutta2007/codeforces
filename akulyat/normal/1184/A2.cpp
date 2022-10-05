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
string s;
vector <ll> p;
map <ll, bool> can;
bool viv=false;

vector <long long> erat(long long last)
{
vector <bool> bad;
vector <long long> r;
for (long long i=0; i<last+10; i++)
  bad.push_back(true);
for (long long i=2; i<=last; i++)
  if (bad[i])
    {
    long long j=2;
    while (j*i<=last)
      {
      bad[j*i]=false;
      j++;
      }
    r.push_back(i);
    }
return r;
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



void check(ll d)
{
vector <string> str(d, "");
for (ll i=0; i<n; i++)
  str[i%d]+=s[i];
bool g=true;
for (ll i=0; i<d; i++)
  {
  ll kol=0;
  for (auto j:str[i])
    kol+=(j=='1');
  if (kol&1)
    g=false;
  }
can[d]=g;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
ll kol=0;
for (auto i:s)
  kol+=(i=='1');

for (ll i=1; i<=n; i++)
  if (n%i==0)
    check(i);

ll ans=0;
for (ll i=1; i<=n; i++)
  if (can[GCD(n, i)])
    ans++;
cout<<ans<<endl;




    return 0;
}
/**
0110101


**/