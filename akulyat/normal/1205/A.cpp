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
bool viv=false;

void bad()
{
cout<<"NO";
exit(0);
}

void check()
{
set <ll> s;
ll sum=0;
for (ll i=0; i<n; i++)
  sum+=m[i];
for (ll i=0; i<2*n; i++)
  {
  ll pa=i+n;
  ll pe=pa+n;
  pa%=2*n;
  pe%=2*n;
  sum+=m[pa];
  sum-=m[pe];
  s.insert(sum);
  if (s.size()>2)
    bad();
  }
/**
for (auto i:s)
  cout<<i<<' ';
cout<<endl;
**/
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
//ll sum=n*(n+1)/2;
for (ll i=0; i<n; i++)
  {
  m.push_back(2*i);
  }
for (ll i=1; i<n; i+=2)
  m[i]^=1;
for (ll i=0; i<n; i++)
  m.push_back(m[i]^1);
check();
cout<<"YES"<<endl;
for (ll i=0; i<2*n; i++)
  cout<<m[i]+1<<' ';




    return 0;
}