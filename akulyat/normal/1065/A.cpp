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

void solve(ll s, ll a, ll b, ll c)
{
s/=c;
ll kol=s/a;
kol*=b;
s+=kol;
cout<<s<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  solve(a, b, c, d);
  }


    return 0;
}