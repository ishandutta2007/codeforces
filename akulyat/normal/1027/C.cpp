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


ll n,i,j,q;
vector <ll> m,have;
bool viv=false;


ld can(ll a, ll b)
{
ld p=(a+b)*(a+b);
p*=4;
p=(ld)p/(ld)(a*b);
return p;
}

void solve()
{
cin>>n;
m.clear();
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }

sort(m.begin(), m.end());
have.clear();

ld best=inf;
pll use;
for (i=0; i<n-1; i++)
  if (m[i]==m[i+1])
    {
    if (!have.empty())
      if (best>can(m[i], have.back()))
        best=can(m[i], have.back()), use={m[i], have.back()};
    have.push_back(m[i]);
    i++;
    }
cout<<use.F<<' ';
cout<<use.F<<' ';
cout<<use.S<<' ';
cout<<use.S<<' ';
cout<<'\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>q;
for (ll u=0; u<q; u++)
  solve();

    return 0;
}

/*

(2a+2b)*(2a+2b)== 4a*a+4b*b+8ab
_______________________________

          a*b

1 1 16 1 16
1 2 36 2 18
1 3 64 3 21.33
1 4 100 4 25
1 99 10000


3 1 64 3 21.22
3 2 100 6 16.666
3 3 144 9 16

4 4 256 16
*/