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
ll p, k;
cin>>p>>k;
ll kol=p/k;
vector <ll> c;
ll nex=k;
for (ll i=0; i<11; i++)
  {
  c.push_back(nex%10);
  nex+=k;
  }
ll fir;
for (ll i=10; i>0; i--)
  if (c[i]==c[0])
    fir=i;
while (c.size()>fir)
  c.pop_back();

ll full=kol/c.size();

ll sum=0;
for (auto i:c)
  sum+=i;
ll ans=0;

ans+=sum*full;
kol%=c.size();
for (ll i=0; i<kol; i++)
  ans+=c[i];
cout<<ans<<'\n';

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