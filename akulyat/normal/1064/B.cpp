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
vector <pll> t;
set <ll> s;
map <ll, ll> kol;
bool viv=false;
ll pm,tmi,tma,m,ans;  

void solve()
{
ll x;
cin>>x;
ll ans=0;
while (x)
  ans+=x&1, x>>=1;
cout<<(1<<ans)<<endl;
}


int main()
{
 ll t;
cin>>t;
while (t)
  solve(), t-=1;



    return 0;
}