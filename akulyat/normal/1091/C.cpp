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
vector <ll> del;
set <ll> s;
bool viv=false;

vector <ll> dels(ll n)
{
vector <ll> r;
for (ll i=1; i<ceil(sqrt(n))+3; i++)
  if (n%i==0&&i*i<=n)
    {
    r.push_back(i);
    r.push_back(n/i);
    if (i*i==n)
      r.pop_back();
    }
return r;
}

void count(ll n, ll p)
{
ll a=1;
ll k=n/p;
ll b=a+k*p;
b-=p;
//cout<<n<<' '<<p<<' '<<a<<' '<<b<<endl;
ll sum=0;
sum=((a+b)*k)/2;
s.insert(sum);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
del=dels(n);
for (auto p:del)
  count(n, p);
for (auto i:s)
  cout<<i<<' ';
cout<<endl;





    return 0;
}