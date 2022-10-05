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

struct tt
{
  ll a,b,c;
};

ll n,i,j;
vector <ll> m;
bool viv=false;
vector <tt> ans;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<12; i++)
  ans.push_back({0, 0, 0});
ans[3]={1, 1, 1};
ans[4]={2, 1, 1};
ans[5]={2, 2, 1};
ans[6]={2, 2, 2};
ans[7]={4, 2, 1};
ans[8]={4, 2, 2};
ans[9]={4, 4, 1};
ans[10]={4, 4, 2};
ans[11]={8, 2, 1};

if (n<=11)
  {
  cout<<ans[n].a<<' ';
  cout<<ans[n].b<<' ';
  cout<<ans[n].c<<' ';
  return 0;
  }

ll a=n/9;
a*=9;
if (n-a<3)
  a-=9;

cout<<ans[n-a].a+a/3<<' ';
cout<<ans[n-a].b+a/3<<' ';
cout<<ans[n-a].c+a/3<<' ';








    return 0;
}