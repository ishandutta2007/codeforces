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
vector <ll> m, p;
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

ll LCM(ll a, ll b)
{
return (a*b)/GCD(a, b);
}

ll kol(ll v)
{
long ans=1;
for (auto i:p)
  {
  ll lans=0;
  while (!(v%i))
    lans++, v/=i;
  ans*=(lans+1);
  }
return ans;
}

void solve()
{
cin>>n;
m.clear();
m.resize(n);
for (auto &i:m)
  cin>>i;
sort(m.begin(), m.end());
ll val=m[0]*m.back();
for (auto i:m)
  if (val%i)
    {
    cout<<-1<<endl;
    return;
    }
//cout<<"AAAAAAaa "<<val<<' '<<kol(val)<<endl;
if (kol(val)==m.size()+2)
  cout<<val<<endl;
else
  cout<<-1<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
p=erat(ml);
ll t;
cin>>t;
while (t)
  solve(), t--;

    return 0;
}