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


ll n,i,j, m;
vector <vector <ll>> a, b;
bool viv=false;

void bad()
{
cout<<"Impossible"<<endl;
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
a.resize(n);
for (auto &i:a)
  i.resize(m);
b.resize(n);
for (auto &i:b)
  i.resize(m);
for (auto &v:a)
  for (auto &i:v)
    cin>>i;
for (auto &v:b)
  for (auto &i:v)
    cin>>i;
for (ll i=0; i<n; i++)
  for (ll j=0; j<m; j++)
    if (a[i][j]>b[i][j])
      swap(a[i][j], b[i][j]);
for (ll i=0; i<n; i++)
  for (ll j=0; j<m-1; j++)
    {
    if (a[i][j]>=a[i][j+1])
      bad();
    if (b[i][j]>=b[i][j+1])
      bad();
    }
for (ll i=0; i<n-1; i++)
  for (ll j=0; j<m; j++)
    {
    if (a[i][j]>=a[i+1][j])
      bad();
    if (b[i][j]>=b[i+1][j])
      bad();
    }
cout<<"Possible";

    return 0;
}
/**
**/