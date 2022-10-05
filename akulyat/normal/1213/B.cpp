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

void solve()
{
cin>>n;
m.clear();
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
reverse(m.begin(), m.end());
vector <ll> st;
st.push_back(m[0]);
for (ll i=1; i<n; i++)
  if (m[i]<=st.back())
    st.push_back(m[i]);
cout<<n-st.size()<<'\n';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t--)
  solve();


    return 0;
}