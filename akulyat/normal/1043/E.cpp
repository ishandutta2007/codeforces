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


ll n,i,j,k;
vector <ll> m,ans;
vector <pll> add,p;
bool viv=false;

void work(ll a, ll b)
{
ll sum=min(p[a].F+p[b].S, p[b].F+p[a].S);
ans[a]-=sum;
ans[b]-=sum;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
ll sum=0;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back(a);
  ans.push_back((n-2)*m.back());
  p.push_back({a, b});
  sum+=m.back();
  add.push_back({b-m[i], i});
  }
/*
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
// */
sort(add.begin(), add.end());
for (auto &i:ans)
  i+=sum;
/*
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
// */
sum=0;
for (i=0; i<n; i++)
  {
  ll v=add[i].S;
  ll z=add[i].F;
  ans[v]+=sum+z*(n-i-1);
  sum+=z;
  }
/*
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
// */
for (i=0; i<k; i++)
  {
  ll a,b;
  cin>>a>>b;
  a--; b--;
  work(a, b);
  }
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;








    return 0;
}