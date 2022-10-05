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


ll n,i,j,y,x1,x2;
vector <pll> m;
vector <ll> sum,p;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

cin>>y>>x1>>x2;

cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  m.push_back({a, b});
  p.push_back(a);
  p.push_back(b);
  }
sum.push_back(0);
for (auto i:m)
  {
  sum.push_back(sum.back()+i.S-i.F);
  sum.push_back(sum.back());
  }



cout.precision(15);
ll q;
cin>>q;
for (ll u=0; u<q; u++)
  {
  ll xi,yi;
  cin>>xi>>yi;
  ld l,r;
  l=(ld)xi+(ld)(x1-xi)*(ld)((ld)yi/(ld)(yi+abs(y)));
  r=(ld)xi+(ld)(x2-xi)*(ld)((ld)yi/(ld)(yi+abs(y)));
  ld len=r-l;
  ld ten=0;
  ll a=-1;
  ll b=n;
  ll per1=lower_bound(p.begin(), p.end(), l)-p.begin();
  if (per1&1)
    ten+=p[per1]-l;
  ll per2=lower_bound(p.begin(), p.end(), r)-p.begin();
  if (per2&1)
    ten-=p[per2]-r;
  ten+=sum[per2];
  ten-=sum[per1];
  cout<<fixed<<(ten/len)*(x2-x1)<<'\n';
  }



    return 0;
}