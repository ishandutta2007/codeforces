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
ll sum=0;
ll my=0;
vector <ll> k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  sum+=a;
  m.push_back(a);
  if (i==0||a*2<=m[0])
    my+=a, k.push_back(i);
  }
if (my*2>sum)
  {
  cout<<k.size()<<endl;
  for (auto i:k)
    cout<<i+1<<' ';
  }
else
  cout<<0;





    return 0;
}