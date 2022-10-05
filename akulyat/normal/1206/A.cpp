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


ll n,i,j, ans, gans, k;
vector <ll> m, l;
bool viv=false;

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
cin>>k;
for (i=0; i<k; i++)
  {
  ll a;
  cin>>a;
  l.push_back(a);
  }
ll a=*max_element(m.begin(), m.end());
ll b=*max_element(l.begin(), l.end());
cout<<a<<' '<<b<<endl;
  
    return 0;
}