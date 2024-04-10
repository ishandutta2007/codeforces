#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const ll kk=1000;
const ll ml=kk*kk;
const ll mod=ml*kk+7;
const ll mod2=998244353;
const ll con=239;
const ll con2=73;
const ll inf=ml*ml*ml+7;

vector <long> m,h,h2;
long i,j,u,n, a, b;
string s;
map <pair <long, long> , long> lhash;
vector <long> ans;
vector <ll> from;
bool viv=false;

void build_hash()
{
for (ll i=0; i<26; i++)
  {
  ll r=0;
  for (ll j=0; j<20; j++)
    r*=10, r+=rand()%10, r%=mod;
  h.push_back(r);
  }
for (ll i=0; i<26; i++)
  {
  ll r=0;
  for (ll j=0; j<20; j++)
    r*=10, r+=rand()%10, r%=mod2;
  h2.push_back(r);
  }
}

/*
pll has(string s)
{
ll n=s.size();
pll r={0, 0};
for (ll i=0; i<n; i++)
  {
  r.F*=con;
  r.F+=h[s[i]-'a'];
  r.F%=mod;
  }
for (ll i=0; i<n; i++)
  {
  r.S*=con2;
  r.S+=h2[s[i]-'a'];
  r.S%=mod2;
  }
lhash.insert(r);
return r;
}
*/

void work(long r)
{
ans[r+1]=a+ans[r];

ll l=r+1-from[r];
for (ll i=l; i<r+1; i++)
  ans[r+1]=min(ans[r+1], ans[i]+b);
}

vector <ll> z_func(string s)
{
ll r=0;
ll from=0;
ll n=s.size();
vector <ll> z(n, 0);
for (ll i=1; i<n; i++)
  {
  if (r>=i)
    {
    z[i]=z[i-from];
    z[i]=min(z[i], r-i+1);
    }
  z[i]=max(z[i], (ll)0);
  if (viv)
    cout<<"start "<<i<<' '<<z[i]<<' '<<from<<' '<<r<<endl;
  while (i+z[i]<n&&s[i+z[i]]==s[z[i]])
    {
    if (i+z[i]>=r)
      r=i+z[i], from=i;
    z[i]++;
    }
  }
if (viv)
  {
  cout<<s<<' ';
  for (auto i:z)
    cout<<i<<' ';
  cout<<endl;
  }
return z;
}

void build(ll r)
{
string st=s.substr(0, r+1);
reverse(st.begin(), st.end());
ll n=st.size();
vector <ll> z=z_func(st);
from.push_back(0);
for (ll i=1; i<n; i++)
  {
  ll len=z[i];
  len=min(len, i);
  from.back()=max(from.back(), len);
  }
}

void prepare()
{
for (ll i=0; i<n; i++)
  build(i);
}




int main()
{


// viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>a>>b;
cin>>s;
ans.resize(n+1, mod);
ans[0]=0;
prepare();

for (long i=0; i<n; i++)
  work(i);
if (viv)
  {
  for (auto i:ans)
    cout<<i<<' ';
  cout<<endl;
  for (auto i:from)
    cout<<i<<' ';
  cout<<endl;
  }
cout<<ans.back();









    return 0;
}