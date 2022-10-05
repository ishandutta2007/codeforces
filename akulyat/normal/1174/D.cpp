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


ll n,i,j, st, x;
vector <ll> m;
bool viv=false;

void print(vector <ll> m)
{
multiset <ll> s;
cout<<st<<' '<<x<<endl;
ll n=m.size();
for (ll i=0; i<n; i++)
  {
  ll now=0;
  for (ll j=i; j<n; j++)
    now^=m[j], s.insert(now);
  }
for (auto i:s)
  cout<<i<<' ';

}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>st>>x;
ll k=1<<st;
ll l=0;
ll rx=x;
while (rx)
  rx>>=1, l++;
l--;
ll mst=1<<l;
ll now=0;
for (ll i=1; i<(1<<st); i++)
  if ((i|(mst))!=i)
    {
    m.push_back(i^now);
    now=i;
    }


cout<<m.size()<<endl;
for (ll i=0; i<m.size(); i++)
  cout<<m[i]<<' ';
cout<<endl;

//viv=true;
if (viv)
  print(m);



    return 0;
}
/**
5


0 3 2 4
0 3 2 4
5 6 7 1

0 1 2 6
0 1 3 5
5 4 2 0

0 2 4 6
5 7 1 3

000
011
010
100

101



0 1 2 3


0 x

0 1 2 3

a^x b^x c^x






**/