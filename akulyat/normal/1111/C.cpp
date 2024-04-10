#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const ll kk=1000;
const ll ml=kk*kk;
const ll mod=ml*kk+7;
const ll inf=ml*ml*ml+7;


ll n,i,j,k,a,b,s,l;
ll ANS;
bool viv=false;
map <ll, ll> pl;
map <ll, ll> leng, have;
set <ll> st;
vector <ll> all;

pll work(ll z, ll leng)
{
if (st.find(z)==st.end())
  return {a, 0};
if (z>=s)
  {
  ll h=upper_bound(all.begin(), all.end(), z)-lower_bound(all.begin(), all.end(), z);
  return {b*h, h};
  }
pll a1=work(2*z, leng/2);
pll a2=work(2*z+1, leng/2);
ll kol=a1.S+a2.S;
ll an1=(ll)b*leng*kol;
ll an2=a1.F+a2.F;
return {min(an1, an2), kol};
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>k>>n>>a>>b;
ll l=(ll)1<<(ll)k;
s=l;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  a+=s;
  ll l=1;
  all.push_back(a);
  while (a>=1)
    st.insert(a), l*=2, a/=2;
  }
sort(all.begin(), all.end());
pll aa=work(1, s);
cout<<aa.F;


    return 0;
}