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
vector <pll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back({a, i});
  }
sort(m.rbegin(), m.rend());
ll st=m[0].F+1;
vector <ll> who(st, -1);
vector <vector <ll>> sons(st);
who[0]=m[0].S*2;
who[st-1]=m[0].S*2+1;

ll pl=1;
for (ll i=1; i<n; i++)
  {
  if (pl>=st-1)
    {
    ll len=m[i].F;
    if (len==1)
      {
      who.push_back(2*m[i].S);
      sons.push_back({});
      who.push_back(2*m[i].S+1);
      sons.push_back({});
      }
    else
      {
      sons[0].push_back(2*m[i].S);
      sons[len-2].push_back(2*m[i].S+1);
      }
    }
  else
    {
    who[pl]=2*m[i].S;
    ll to=pl+m[i].F-1;
    if (to==who.size()-1)
      {
      who.push_back(2*m[i].S+1);
      sons.push_back({});
      }
    else
      {
      sons[to].push_back(2*m[i].S+1);
      }
    }
  pl++;
  }

ll k=1;
for (ll i=0; i<who.size(); i++)
  {
  for (auto s:sons[i])
    cout<<who[i]+k<<' '<<s+k<<'\n';
  }
for (ll i=0; i<who.size()-1; i++)
  {
  cout<<who[i]+k<<' '<<who[i+1]+k<<'\n';
  }

if (viv)
  {
  cout<<"Line "<<who.size()<<": ";
  for (auto i:who)
    cout<<i<<' ';
  cout<<endl;
  for (ll i=0; i<who.size(); i++)
    {
    cout<<"sons: ";
    for (auto s:sons[i])
      cout<<s<<' ';
    cout<<endl;
    }
  }



    return 0;
}