#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
ifstream in;
ofstream out;

ll n,i,j,ans,kol;
vector <ll> m,st;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  if (b!=0)
    {
    ans+=a;
    kol+=b-1;
    }
  else
    m.push_back(a);
  }
kol++;
sort(m.rbegin(), m.rend());
st.push_back(0);
for (auto i:m)
  st.push_back(st.back()+i);
kol=min((ll)m.size(), kol);
ans+=st[kol];

cout<<ans;

    return 0;
}