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


ll n,i,j, nf, ans1, ans2, same;
vector <pll> m;
vector <ll> pa, pb, f, sa, sb, sm;
bool viv=false;

void precalc()
{
f.push_back(1);
for (ll i=1; i<n+100; i++)
  f.push_back((f.back()*i)%mod);

sa.resize(n+1, 1);
sb.resize(n+1, 1);
sm.resize(n+1, 1);
for (ll i=1; i<n; i++)
  if (pa[i]==pa[i-1])
    sa[i]+=sa[i-1];
for (ll i=1; i<n; i++)
  if (pb[i]==pb[i-1])
    sb[i]+=sb[i-1];
for (ll i=1; i<n; i++)
  if (m[i]==m[i-1])
    sm[i]+=sm[i-1];

ans1=1;
ans2=1;
same=1;
for (ll i=0; i<n-1; i++)
  if (m[i].S>m[i+1].S)
    same=0;

for (ll i=0; i<n; i++)
  if (sa[i+1]==1)
    ans1*=f[sa[i]], ans1%=mod;
for (ll i=0; i<n; i++)
  if (sb[i+1]==1)
    ans2*=f[sb[i]], ans2%=mod;
for (ll i=0; i<n; i++)
  if (sm[i+1]==1)
    same*=f[sm[i]], same%=mod;

if (viv)
  cout<<ans1<<' '<<ans2<<' '<<same<<endl;

ll ans=f[n];
ans-=ans1;
ans-=ans2;
ans+=same;
ans%=mod;
while (ans<0)
  ans+=mod;
cout<<ans<<endl;
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a, b;
  cin>>a>>b;
  m.push_back({a, b});
  pa.push_back(a);
  pb.push_back(b);
  }
sort(m.begin(), m.end());
sort(pa.begin(), pa.end());
sort(pb.begin(), pb.end());
precalc();



    return 0;
}