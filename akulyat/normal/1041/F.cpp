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


ll n1,n2,i,j,zz1,zz2;
vector <ll> m1,m2;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n1>>zz1;
for (i=0; i<n1; i++)
  {
  ll a;
  cin>>a;
  m1.push_back(a);
  }
cin>>n2>>zz2;
for (i=0; i<n2; i++)
  {
  ll a;
  cin>>a;
  m2.push_back(a);
  }
vector <ll> st;
st.push_back(1);
for (i=1; i<34; i++)
  st.push_back(st.back()*2);

ll ans=2;
for (auto v:st)
  {
  vector <ll> m;
  for (auto i:m1)
    m.push_back(i);
  for (auto i:m2)
    m.push_back(i-v);
  for (auto &i:m)
    i=(i%(2*v)+2*v)%(2*v);
  sort(m.begin(), m.end());
  vector <ll> bs;
  bs.push_back(1);
  for (i=1; i<m.size(); i++)
    if (m[i]==m[i-1])
      bs.push_back(bs.back()+1);
    else
      bs.push_back(1);
  ll lans=1;
  for (auto i:bs)
    lans=max(lans, i);
  ans=max(ans, lans);
 /*
  cout<<v<<' '<<lans<<endl;
  for (auto i:m)
    cout<<i<<' ';
  cout<<endl;
// */
  }

cout<<ans;







    return 0;
}