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
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
vector <ll> ans;
ans.push_back(1);
for (i=1; i<n; i++)
  if (m[i]<=m[i-1]*2)
    ans.push_back(ans.back()+1);
  else
    ans.push_back(1);

ll vv=0;
for (auto i:ans)
  vv=max(vv, i);

cout<<vv<<endl;


    return 0;
}