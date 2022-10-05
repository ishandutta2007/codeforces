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
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ll mm=500*kk;
//ll mm=10;
vector <ll> add,w;
for (i=0; i<n; i++)
  w.push_back(mm-n+i);
for (i=n-1; i>=0; i--)
  {
  ll c=w[i]-m[i];
  c%=mm;
  c+=mm;
  c%=mm;
  add.push_back(c);
  for (j=0; j<i; j++)
    m[j]+=add.back();
  }
//reverse(add.begin(), add.end());
cout<<n+1<<endl;
for (i=0; i<n; i++)
  cout<<1<<' '<<n-i<<' '<<add[i]<<'\n';
cout<<2<<' '<<n<<' '<<mm<<endl;




    return 0;
}