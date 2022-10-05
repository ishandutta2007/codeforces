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


ll n,i,j,com;
vector <ll> m,f,s;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;

for (i=0; i<n; i++)
  {
  ll v;
  cout<<"? "<<i<<' '<<0<<endl;
  cin>>v;
  f.push_back(v);
  }
for (i=0; i<n; i++)
  {
  ll v;
  cout<<"? "<<0<<' '<<i<<endl;
  cin>>v;
  s.push_back(v);
  }
com=s[0];

ll num=0;
vector <ll> ans(n, 0);
vector <ll> ans2(n, 0);
for (ll z=0; z<n; z++)
  {
  // ok, b[i]==0
  vector <ll> p,b;
  ll pz=-1;
  for (i=0; i<n; i++)
    {
    p.push_back(f[i]^s[z]^com);
    if (p.back()==0)
      pz=i;
    }
  if (pz!=-1)
    {
    for (i=0; i<n; i++)
      b.push_back(f[pz]^s[i]^com);
    bool cor=true;
    vector <short> hp(n, 0), hb(n, 0);
    for (i=0; i<n; i++)
      if (p[i]>=n||b[i]>=n)
      cor=false;
    if (cor)
      for (i=0; i<n; i++)
        {
        hp[p[i]]++, hb[b[i]]++;
        if (hp[p[i]]>1||hb[b[i]]>1)
          cor=false;
        }
    if (cor)
      {
      for (i=0; i<n; i++)
        if (p[b[i]]!=i)
          cor=false;
      if (cor)
        {
        num++;
        if (num==1)
          ans=p, ans2=b;
        }
      }
    }
  }

cout<<'!'<<endl;
cout<<num<<endl;
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;














    return 0;
}