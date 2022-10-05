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
ll ans;

void solve1(ll m)
{
ans+=(m/6)*6;
m%=6;
if (m>3)
  ans+=(m-3)*2;
cout<<ans;
exit(0);
}

void solve2(ll m)
{
if (m==2)
  {
  cout<<0;
  exit(0);
  }
if (m==3||m==7)
  {
  cout<<2*m-2;
  exit(0);
  }
cout<<2*m;
exit(0);
}
int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll m;
cin>>n>>m;
if (n>m)
  swap(n, m);
if (n==1)
  solve1(m);
if (n==2)
  solve2(m);

ans=(n*m/2)*2;
cout<<ans;

/*
2 3 2
2 4 0
2 5 0
2 6 0
2 7 2

3 3 1
3 4 0
3 5 1
3 6 0
*/


    return 0;
}