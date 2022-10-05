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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j,m,k,ans;
bool viv=false;
vector <ll> st,f,fobr;

long long obr(long long v, long long mod)
{
long long i=0;
long long st=mod-2;
vector <long long> bin;
long long l=0;
while(st>0)
  {
  bin.push_back(st&1);
  st/=2;
  l++;
  }

vector <long long> sq;
sq.push_back(v);
for (i=1; i<l; i++)
  {
  long long s=sq.back();
  s*=s;
  s%=mod;
  sq.push_back(s);
  }

long long ans=1;
for (i=0; i<l; i++)
  if (bin[i])
    {
    ans*=sq[i];
    ans%=mod;
    }
return ans;
}


void prepare()
{
f.push_back(1);
for (ll i=1; i<=200*kk; i++)
  f.push_back(f.back()*i), f.back()%=mod;
for (auto i:f)
  fobr.push_back(obr(i, mod));
st.push_back(1);
for (ll i=1; i<=200*kk; i++)
  st.push_back(st.back()*(m-1)), st.back()%=mod;
}

ll C(ll n, ll k)
{
ll r=1;
r*=f[n];
r%=mod;
r*=fobr[k];
r%=mod;
r*=fobr[n-k];
r%=mod;
return r;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k;
if (m==1&&k>0)
  {
  cout<<0;
  return 0;
  }
prepare();
ans=1;
ans*=C(n-1, k);
ans%=mod;
ans*=m;
ans%=mod;
ans*=st[k];
ans%=mod;
cout<<ans<<endl;



    return 0;
}