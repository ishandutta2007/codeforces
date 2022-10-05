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
m.resize(n);
for (i=1; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  m[i]=a;
  }
vector <ll> ans;
ll cur=n-1;
while (cur!=0)
  ans.push_back(cur), cur=m[cur];
ans.push_back(cur);
reverse(ans.begin(), ans.end());
for (auto i:ans)
  cout<<i+1<<' ';


    return 0;
}