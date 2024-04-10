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
vector <ll> m,v,m1,v1;
bool viv=false;

vector <ll> work(vector <ll> m)
{
ll g=m[0];
vector <ll> v;
for (ll i=0; i<m.size()-1; i++)
  v.push_back(m[i+1]-m[i]);
sort(v.begin(), v.end());
v.push_back(g);
return v;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  v.push_back(a);
  }

m1=work(m);
v1=work(v);
if (m1!=v1)
  cout<<"No";
else
  cout<<"Yes";


    return 0;
}