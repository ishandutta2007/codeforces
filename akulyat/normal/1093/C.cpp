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
vector <ll> m1,m2,b;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n/2; i++)
  {
  ll a;
  cin>>a;
  b.push_back(a);
  }
m1.push_back(b.back()/2);
m2.push_back(b.back()-m1.back());
b.pop_back();
while (b.size())
  {
  ll v=b.back()/2;
  v=min(v, m1.back());
  ll v2=m2.back();
  v=min(v, b.back()-v2);
  m1.push_back(v);
  m2.push_back(b.back()-m1.back());
  b.pop_back();
  }

reverse(m1.begin(), m1.end());
for (auto i:m1)
  cout<<i<<' ';
for (auto i:m2)
  cout<<i<<' ';





    return 0;
}