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
const ld eps=1e-8;

ll n,i,j;
vector <ll> m;
vector <ll> good,nice;
bool viv=false;
vector <pll> nor;

void work(ll v)
{
nor.clear();
for (ll i=1; i<ml; i++)
  {
//  i*i+i*(a-1)=v;
//  a=(v-i*i)/i+1;
  ld s1=(ld)(v-i*i)/i+1.0;
  if (s1<1+eps)
    return;
  if (!((v-i*i)%i))
    {
    ll s=(v-i*i)/i+1;
    ll f=s+2*(i-1);
    if (viv)
      cout<<v<<' '<<s<<' '<<f<<endl;
    if (s%2!=0)
      nor.push_back({s/2, f/2+1});
    }
  }
if (viv)
  {
  cout<<v<<':';
  for (auto p:nor)
    cout<<p.F<<' '<<p.S<<"     ";
  cout<<endl;
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
good.push_back(1);
nice.push_back(1);
//viv=true;
for (i=0; i<n/2; i++)
  {
  ll a;
  cin>>a;
  work(a);
    good.push_back(inf);
  for (auto j:nor)
    {
    ll a=j.F;
    ll b=j.S;
    if (good[2*i]<=a)
      if (b<good.back()&&a>=good[2*i])
        {
        good.back()=b;
        nice[2*i]=a;
        }
    }
  nice.push_back(good.back());
  if (good.back()==inf)
    {
    cout<<"No";
    return 0;
    }
  if (i<n/2-1)
    good.push_back(good.back()+1),
    nice.push_back(good.back()+1);
  }
if (viv)
{
for (auto i:nice)
  cout<<i<<' ';
cout<<endl;
}
cout<<"Yes"<<endl;
m.push_back(0);
for (auto i:nice)
  m.push_back(i*i);
for (ll i=1; i<m.size(); i++)
  cout<<m[i]-m[i-1]<<' ';






    return 0;
}