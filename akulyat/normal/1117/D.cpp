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


ll n,i,j, k;
bool viv=false;
vector <vector <ll>> vec;
vector <vector <ll>> mat;
void build()
{
vec.resize(k);
for (auto &v:vec)
  v.resize(1, 1);
mat.resize(k);
for (auto &str:mat)
  str.resize(k, 0);
for (ll i=0; i<k-1; i++)
  mat[i][i+1]=1;
mat[k-1][0]=1;
mat[k-1][k-1]=1;
}

ll msum(ll a, ll b)
{return (a+b)%mod;}

ll mprod(ll a, ll b)
{return (a*b)%mod;}

vector <vector <ll>> mult(vector <vector <ll>> m1, vector <vector <ll>> m2)
{
ll n=m1[0].size();
ll a=m1.size();
ll b=m2[0].size();
vector <vector <ll>> res;
res.resize(a);
for (auto &str:res)
  str.resize(b);
for (ll i=0; i<a; i++)
  for (ll j=0; j<b; j++)
    for (ll u=0; u<n; u++)
        res[i][j]=msum(res[i][j], mprod(m1[i][u], m2[u][j]));
return res;
}

vector <vector <ll>> step(vector <vector <ll>> m, ll st)
{
ll n=m.size();
vector <ll> b;
while (st)
  b.push_back(st&1), st>>=1;
vector <vector <ll>> res(n);
for (auto &str:res)
  str.resize(n);
for (ll i=0; i<n; i++)
  res[i][i]=1;
vector <vector <vector <ll>>> sq;
sq.push_back(m);
while (sq.size()<b.size())
  sq.push_back(mult(sq.back(), sq.back()));
for (ll i=(ll)b.size()-1; i>=0; i--)
  if (b[i])
    res=mult(res, sq[i]);
return res;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
build();
vec=mult(step(mat, n), vec);

cout<<vec[0][0];





    return 0;
}