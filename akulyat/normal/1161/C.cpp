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
ll nex;


void a()
{
cout<<"Alice";
exit(0);
}

void b()
{
cout<<"Bob";
exit(0);
}

void step()
{

}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
if (m[0]==m[n/2])
  b();
a();

/*
if (m[n/2]==1)
  b();
if (m[0]==1)
  a();

nex=0;
while (m[0]!=1)
  step();
*/



    return 0;
}
/**
2 2 2 2 2  || 24 42  2 3  2 4 2

2 2 3 3
2 2 2 2







**/