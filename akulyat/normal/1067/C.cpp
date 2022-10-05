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


void solve3()
{
ll k=(n/3)*2;
n-=k;
for (i=0; i<k; i++)
  cout<<0<<' '<<i<<'\n';
ll y=0;
ll x=3;
while (n)
  {
//  x*=-1;
  cout<<x<<' '<<y<<endl;
  if (x>0)
    y+=2;
  n--;
  }
}

void solve4()
{
ll k=n/2;
n-=k;
for (i=-k/2; i<-k/2+k; i++)
  cout<<i<<' '<<0<<endl;
k=n/2;
n-=k;
ll y=1;
while (k)
  cout<<0<<' '<<y<<endl, y++, k--;
y=-1;
while (n)
  cout<<0<<' '<<y<<endl, y--, n--;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
if (n<20)
  solve3();
solve4();



    return 0;
}