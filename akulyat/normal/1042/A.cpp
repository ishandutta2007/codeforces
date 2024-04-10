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


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll k;
cin>>n>>k;
ll ma=-inf;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  ma=max(ma, a);
  m.push_back(a);
  }
sort(m.rbegin(), m.rend());
ma+=k;
while (k)
  {
  m.back()++;
  j=n-1;
  while (j>0&&m[j]>m[j-1])
    swap(m[j], m[j-1]), j--;
  k--;
  }

cout<<m[0]<<' '<<ma<<endl;



    return 0;
}