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
ll kol[10];
string s,t;


int main()
{
cin>>n;
cin>>s>>t;

for (i=0; i<n; i++)
  kol[2*(s[i]-'0')+(t[i]-'0')]++;

cout<<kol[0]*(kol[2]+kol[3])+kol[1]*kol[2]<<endl;





    return 0;
}