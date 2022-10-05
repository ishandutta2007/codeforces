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

void checker(ll n)
{
vector <vector <ll> > d;
d.resize(n);
for (auto &v:d)
  v.resize(n);
vector <ll> r(n, 0), c(n, 0);
ll nex=0;
for (ll i=0; i<n/2; i++)
  for (ll j=0; j<n/2; j++)
    {
    d[2*i][2*j]=nex;
    d[2*i][2*j+1]=nex+1;
    d[2*i+1][2*j]=nex+2;
    d[2*i+1][2*j+1]=nex+3;
    r[2*i]^=nex;
    r[2*i]^=nex+1;
    r[2*i+1]^=nex+2;
    r[2*i+1]^=nex+3;
    c[2*j]^=nex;
    c[2*j]^=nex+2;
    c[2*j+1]^=nex+1;
    c[2*j+1]^=nex+3;
    nex+=4;
    }
for (auto v:d)
  {
  for (auto i:v)
    cout<<i<<' ';
  cout<<endl;
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
checker(n);

    return 0;
}