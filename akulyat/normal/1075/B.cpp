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
vector <ll> m,t,ty,w;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll k;
cin>>n>>k;
n+=k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  ty.push_back(a);
  if (a)
    t.push_back(i);
  }
reverse(t.begin(), t.end());
vector <ll> kol;
kol.resize(n);
for (i=0; i<n; i++)
  {
  if (ty[i])
    w.push_back(t.back()), t.pop_back();
  else
    {
    if (w.empty())
      kol[t.back()]++;
    if (t.empty())
      kol[w.back()]++;
    if (!t.empty()&&!w.empty())
      {
      if ((abs(m[w.back()]-m[i])<=abs(m[t.back()]-m[i])))
        kol[w.back()]++;
      else
        kol[t.back()]++;
      }
    }
  }
for (i=0; i<n; i++)
  if (ty[i])
    cout<<kol[i]<<' ';



    return 0;
}