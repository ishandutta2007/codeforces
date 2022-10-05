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


ll n,i,j,ch,k;
vector <ll> m,nm,pr;
bool viv=false;
map <ll, ll> mp;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
ch=(1<<k)-1;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  nm.push_back(a^ch);
  }
pr.push_back(0);
mp[0]=1;
ll ans=n*(n+1)/2;
for (i=0; i<n; i++)
  {
  ll a=pr.back()^m[i];
  ll b=pr.back()^nm[i];
  if (mp.find(a)==mp.end())
    mp[a]=0;
  if (mp.find(b)==mp.end())
    mp[b]=0;
  if (mp[a]<=mp[b])
    pr.push_back(a);
  else
    pr.push_back(b);
  ans-=mp[pr.back()];
  mp[pr.back()]++;
  }
/*
for (auto i:pr)
  cout<<i<<' ';
cout<<endl;
// */
cout<<ans;


    return 0;
}