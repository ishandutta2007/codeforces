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
vector <ll> m,kol;
vector <ll> sh[200*kk];
bool viv=false;

void bad()
{
cout<<"Impossible";
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
kol.assign(n, 0);
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  kol[a]++;
  m.push_back(a);
  }
ll nex=1;
for (ll i=0; i<n; i++)
  {
  ll s=n-i;
  if (kol[i]%(s))
    bad();
  ll dif=kol[i]/s;
  for (j=nex; j<nex+dif; j++)
    for (ll u=0; u<s; u++)
        sh[i].push_back(j);
  nex=j;
  }
cout<<"Possible"<<endl;
for (auto i:m)
  cout<<sh[i].back()<<' ', sh[i].pop_back();



    return 0;
}