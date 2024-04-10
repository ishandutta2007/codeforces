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


ll n,i,j,x,ans,kolx;
vector <ll> m,pr,suf;
vector <ll> pl[501*kk];
bool viv=false;

void use(ll v)
{
set <ll> s;
for (ll j=0; j<pl[v].size(); j++)
  {
  ll dif=j+1-pr[pl[v][j]+1];
  s.insert(dif-1);
  ans=max(ans, kolx+dif-(*s.begin()));
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>x;
x--;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  pl[a].push_back(i);
  m.push_back(a);
  }
pr.push_back(0);
for (i=0; i<n; i++)
  {
  pr.push_back(pr.back());
  if (m[i]==x)
    pr.back()++;
  }
for (auto i:pr)
  suf.push_back(pr.back()-i);
ans=pl[x].size();
kolx=ans;
for (i=0; i<501*kk; i++)
  if (i!=x)
    use(i);

cout<<ans<<endl;


    return 0;
}