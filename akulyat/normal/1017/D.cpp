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
const long long ss=1024*4+100;

ll n1,n2,l,i,j,u,toxor,kol;
vector <ll> m;
vector <ll> pr;
ll have[ss];
ll ans[ss][102];
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>l>>n1>>n2;

for (i=0; i<l; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
reverse(m.begin(), m.end());

for (u=0; u<l; u++)
  toxor+=(1ll<<u);
kol=1ll<<l;

for (i=0; i<kol; i++)
  {
  ll lpr=0;
  ll i1=i;
  for (u=0; u<l; u++)
    {
    if (i1&1)
      lpr+=m[u];
    i1/=2;
    }
  pr.push_back(lpr);
  }

for (i=0; i<n1; i++)
  {
  string s;
  cin>>s;
  ll z=0;
  for (u=0; u<l; u++)
    z*=2, z+=s[u]-'0';
  have[z]++;
  }

for (i=0; i<kol; i++)
  {
  for (j=0; j<kol; j++)
    {
    ll lpr=pr[i^j^toxor];
    if (lpr<=100)
      ans[i][lpr]+=have[j];
    }
  }
for (i=0; i<kol; i++)
  {
  for (u=1; u<=100; u++)
    ans[i][u]+=ans[i][u-1];
  }

for (i=0; i<n2; i++)
  {
  string s;
  ll v;
  cin>>s>>v;
  ll z=0;
  for (u=0; u<l; u++)
    z*=2, z+=s[u]-'0';
  cout<<ans[z][v]<<'\n';
  }





    return 0;
}
/*
2 4 5
40 20
01
01
10
11
00 20
00 40
11 20
11 40
11 60

2 4 5
4 2
01
01
10
11
00 2
00 4
11 2
11 4
11 6

*/