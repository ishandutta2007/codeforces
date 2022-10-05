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

void no()
{
cout<<"NO";
exit(0);
}

void yes()
{
cout<<"YES";
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll sum=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  sum+=a;
  }
if (sum&1)
  no();
sort(m.begin(), m.end());
if (m.back()*2>sum)
  no();
yes();






    return 0;
}