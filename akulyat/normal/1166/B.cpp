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

void print(ll a)
{
ll b=n/a;
string s;
vector <char> bk;
bk.push_back('a');
bk.push_back('e');
bk.push_back('i');
bk.push_back('o');
bk.push_back('u');
for (ll i=0; i<a; i++)
  for (ll j=0; j<b; j++)
    s+=bk[(i+j)%5];
cout<<s;
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (ll a=1; a<=n; a++)
  if (!(n%a))
    {
    ll b=n/a;
    if (min(a, b)>=5)
      print(a);
    }
cout<<-1;




    return 0;
}