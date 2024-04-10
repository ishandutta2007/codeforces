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
cin>>n;
string s;
cin>>s;
while (!s.empty()&&s.back()=='>')
  s.pop_back();
reverse(s.begin(), s.end());
while (!s.empty()&&s.back()=='<')
  s.pop_back();

cout<<n-s.size();









    return 0;
}