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
const long long inf=998244353;


ll n,i,j,l,r,k,d;
ll st[20];
vector <ll> m,kol,sc;
vector <ll> reb[10*kk];
map <ll, ll> mp;
bool viv=false;

void count()
{
for (ll i=0; i<d; i++)
  {
  ll j=i;
  kol.push_back(0);
  while (j)
    kol.back()+=j&1, j>>=1;
  }
//kol[0]=1;
}

void build()
{
d=1024;
count();
for (ll i=0; i<d; i++)
  {
  ll i1=i;
  for (ll j=0; j<10; j++)
    {
    if (i1&1)
      reb[i].push_back(i-(1<<j));
    i1>>=1;
    }
  }
for (ll i=0; i<d; i++)
  {
  sc.push_back(0);
  ll i1=i;
  for (ll j=0; j<10; j++)
    sc.back()+=j*(i1&1), i1>>=1;
  }
}


ll fkol(ll r, ll z)
{
vector <bool> cif(10, false);
ll r1=r;
ll now=0;
while (r1)
  {
  if (!cif[r1%10])
    cif[r1%10]=true, now+=st[r1%10];
  r1/=10;
  }
ll var[20][d+10];
ll skol[20][d+10];
for (ll i=0; i<20; i++)
  for (ll j=0; j<d+10; j++)
    var[i][j]=0,
    skol[i][j]=0;
skol[0][now]=r%mod;
var[0][now]=1;
for(ll i=1; i<=z; i++)
  {
  for (ll j=0; j<d; j++)
    {
    for (auto s:reb[j])
      {
      if (j!=1)
        var[i][j]+=var[i-1][s];
      skol[i][j]+=skol[i-1][s]*10;
      skol[i][j]+=var[i-1][s]*(mp[j-s]);
      var[i][j]%=mod;
      skol[i][j]%=mod;
      }
    var[i][j]+=var[i-1][j]*kol[j];
    skol[i][j]+=skol[i-1][j]*10*kol[j];
    skol[i][j]+=sc[j]*var[i-1][j];
    var[i][j]%=mod;
    skol[i][j]%=mod;
//    cout<<"{"<<j<<' '<<var[i][j]<<' '<<skol[i][j]<<"} ";
    }
  }
ll res=0;
for (ll j=0; j<d; j++)
  if (kol[j]<=k)
    res+=skol[z][j], res%=mod;
//cout<<"Fkol "<<r<<' '<<z<<"= "<<res<<endl;
return res;
}

ll work(ll r)
{
if (r<10ll)
  return r*(r+1)/2;
ll ans=0;
ll z=0;
ans+=fkol(r, 0);
while (r)
  {
  ll c=r%10;
  r/=10;
  for (ll i=0; i<c; i++)
    ans+=fkol(10*r+i, z), ans%=mod;
  z++;
  }
z-=2;
while (z)
  ans+=fkol(0, z), ans%=mod, z--;
return ans;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>l>>r>>k;
for (i=0; i<10; i++)
  st[i]=(1<<i);
for (i=0; i<10; i++)
  mp[st[i]]=i;
build();
ll ans=0;
ans+=work(r);
ans-=work(l-1);
ans=(ans%mod+mod)%mod;
cout<<ans<<endl;
/*
for (i=0; i<=50; i++)
  cout<<i<<'_'<<work(i)<<' ';
cout<<endl;
*/

    return 0;
}