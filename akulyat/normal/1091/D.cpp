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


ll n,i,j;
ll ans=0;
vector <ll> m,f,s;
bool viv=false;

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
for (ll i=1; i<2*ml; i++)
  f.push_back(f.back()*i), f.back()%=mod;
for (ll i=0; i<n-2; i++)
  s.push_back((i+1)*(i+3)), s.back()%=mod;
reverse(s.begin(), s.end());
for (ll i=n-1; i>=2; i--)
  m.push_back(i);
for (auto &i:m)
  i=obr(i, mod);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
prepare();
ans=f[n];
ll st=n-1;
//cout<<st<<' ';
//ans-=st;
ans+=mod;
ans%=mod;
for (i=0; i<n-2; i++)
  {
  ans+=((st*i)%mod);
  ans%=mod;
  st*=s[i];
  st%=mod;
  st*=m[i];
  st%=mod;
//  st*=(i+2);
  st%=mod;
//  cout<<st<<' ';
  }
//cout<<endl;
ans+=((st*i)%mod);
ans%=mod;
cout<<ans<<endl;
/*
cout<<"          "<<ans<<endl;
for (auto i:m)
  cout<<i<<' ';
cout<<endl;
for (auto i:s)
  cout<<i<<' ';
cout<<endl;
*/







    return 0;
}