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


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
set <ll> s;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  s.insert(a);
  m.push_back(a);
  }


ll k=s.size();

map <ll, bool> was;
for (auto i:s)
  was[i]=true;
ll kol=k;

ll last=0;
while (true)
  {
  if (was[m.back()])
    {
    kol--;
    was[m.back()]=false;
    }
  if (kol==0)
    {
    cout<<m.back()+1;
    return 0;
    }
  m.pop_back();
  }


    return 0;
}