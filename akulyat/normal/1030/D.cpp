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


ll n,i,j,m,k;
bool viv=false;

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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k;
ll n1=n;
ll m1=m;
if (k==1)
  {
  cout<<"NO";
  return 0;
  }
//ll s=n*m;
ll d1=GCD(n, k);
n/=d1;
k/=d1;
ll d2=GCD(m, k);
m/=d2;
k/=d2;

if (k>2)
  {
  cout<<"NO";
  return 0;
  }
if (k==1)
  {
  if (n!=n1)
    n*=2;
  else
    m*=2;
  }

pll a={0, 0};
pll b={n, 0};
pll c={0, m};


cout<<"YES"<<endl;
cout<<a.F<<' '<<a.S<<endl;
cout<<b.F<<' '<<b.S<<endl;
cout<<c.F<<' '<<c.S<<endl;


    return 0;
}