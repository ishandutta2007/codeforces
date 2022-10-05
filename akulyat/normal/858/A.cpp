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
ll k;
cin>>n>>k;
ll a=0,b=0;
ll n1=n;
while (n1%2==0)
  n1/=2, a++;
while (n1%5==0)
  n1/=5, b++;

a=k-a;
b=k-b;
while (a>0)
  n*=2, a--;
while (b>0)
  n*=5, b--;
cout<<n<<endl;



    return 0;
}