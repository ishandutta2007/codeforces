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


ll n,i,j,a,b;
vector <ll> m,p,ma,mb;
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

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>a>>b;
n=a+b;

for (i=1; i<=10*ml; i++)
  if (a%i==0&&i*i<=a)
    ma.push_back(i),
    ma.push_back(a/i);
sort(ma.begin(), ma.end());
for (i=1; i<=10*ml; i++)
  if (b%i==0&&i*i<=b)
    mb.push_back(i),
    mb.push_back(b/i);
sort(mb.begin(), mb.end());

ll ans=2*n+2;
for (i=1; i<15*ml; i++)
  if (n%i==0&&i*i<=n)
    {
    ll z=lower_bound(ma.begin(), ma.end(), i)-ma.begin();
    if (z&&ma[z]!=i)
      z--;
    if (ma[z]<=i&&a/ma[z]<=n/i)
      ans=min(ans, 2*i+2*(n/i));

    z=lower_bound(mb.begin(), mb.end(), i)-mb.begin();
    if (z&&mb[z]!=i)
      z--;
    if (mb[z]<=i&&b/mb[z]<=n/i)
      ans=min(ans, 2*i+2*(n/i));
    }

cout<<ans;







    return 0;
}