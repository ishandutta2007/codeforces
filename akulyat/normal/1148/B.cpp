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


ll n,i,j, m, ta, tb, k, ans;
vector <ll> a, b;
bool viv=false;

void use(ll num)
{
ll ost=k-num;
ll ar=a[num];
ll v=lower_bound(b.begin(), b.end(), ar)-b.begin();
v+=ost;
if (v>=b.size())
  {
  cout<<-1<<endl;
  exit(0);
  }
ans=max(ans, b[v]+tb);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>ta>>tb>>k;
for (i=0; i<n; i++)
  {
  ll x;
  cin>>x;
  a.push_back(x+ta);
  }
ans=-1;
for (i=0; i<m; i++)
  {
  ll x;
  cin>>x;
  b.push_back(x);
  }
if (k>=n)
  {
  cout<<-1<<endl;
  exit(0);
  }
for (ll i=0; i<=k; i++)
  use(i);

cout<<ans<<endl;



    return 0;
}

/**
2 4 6 8
2 3 4 10 11







**/