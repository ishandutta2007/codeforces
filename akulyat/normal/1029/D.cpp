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
vector <ll> m[12];
bool viv=false;

string ll_to_str(long long v)
{
string s="";
if (v==0)
  return "0";
bool obr=false;
if (v<0)
  obr=true;
v=abs(v);
while (v>0)
  {
  short e=v%10;
  s+=char('0'+e);
  v/=10;
  }
reverse(s.begin(), s.end());
if (obr)
  s='-'+s;
return s;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  ll len=ll_to_str(a).size();
  a%=k;
  m[len].push_back(a);
  }
for (i=0; i<=10; i++)
  sort(m[i].begin(), m[i].end());

vector <ll> st;
st.push_back(1);
for (i=1; i<12; i++)
  st.push_back(st.back()*10);

ll ans=0;
for (i=0; i<=10; i++)
  {
  for (auto j:m[i])
    {
    for (ll u=0; u<=10; u++)
      {
      ll ost=j;
      ost*=st[u/2];
      ost%=k;
      ost*=st[u-u/2];
      ost%=k;
      ost=(k-ost)%k;
      ans+=upper_bound(m[u].begin(), m[u].end(), ost)-m[u].begin();
      ans-=lower_bound(m[u].begin(), m[u].end(), ost)-m[u].begin();
      if (i==u&&ost==j)
        ans--;
      }
    }
  }

cout<<ans;

    return 0;
}