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
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  m.push_back({-a-b-c-d, i});
  }

sort(m.begin(), m.end());

for (i=0; i<n; i++)
  if (m[i].S==0)
    cout<<i+1<<endl;

//for (auto i:m)
//  cout<<i.F<<' '<<i.S<<endl;


    return 0;
}
/*
6
100 80 90 99
60 60 60 60
90 60 100 60
60 100 60 80
100 100 0 100
0 0 0 0



*/