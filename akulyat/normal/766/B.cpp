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
cin>>n;
if (n>=150)
  {
  cout<<"YES";
  return 0;
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
for (i=2; i<m.size(); i++)
  if (m[i]<m[i-1]+m[i-2])
    {
    cout<<"YES";
    return 0;
    }
cout<<"NO";
 
    return 0;
}