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
string s;
vector <ll> m;
bool viv=false;

void check(string t)
{
for (ll i=0; i<n; i++)
  if (t[i]!=t[n-1-i])
    return;
if (s==t)
  return;
cout<<1<<endl;
exit(0);
}

void by1()
{
for (ll i=1; i<n; i++)
  {
  string t=s.substr(i, n-i);
  t+=s.substr(0, i);
  check(t);
  }
}

void by2()
{
ll k=n/2;
for (ll i=0; i<k-1; i++)
  if (s[i]!=s[i+1])
    {
    cout<<2<<endl;
    exit(0);
    }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n=s.size();
by1();
by2();
cout<<"Impossible";




    return 0;
}