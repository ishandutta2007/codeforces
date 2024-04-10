#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <ll> m;
string s,t;


int main()
{
cin>>s>>t;

while (s.size()>0&&t.size()>0&&t.back()==s.back())
  {
  s.pop_back();
  t.pop_back();
  }

cout<<s.size()+t.size();


    return 0;
}