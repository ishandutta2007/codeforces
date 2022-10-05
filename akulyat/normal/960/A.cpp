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

int main()
{
string s;
cin>>s;
string s2;
s2=s;
sort(s2.begin(), s2.end());
n=s.size();
for (i=0; i<n; i++)
  kol[s[i]-'a']++;
if (s!=s2)
  {cout<<"NO"; return 0; }
if (kol[0]==0)
  {cout<<"NO"; return 0; }
if (kol[1]==0)
  {cout<<"NO"; return 0; }
if (kol[2]==0)
  {cout<<"NO"; return 0; }
if (kol[2]!=kol[1]&&kol[2]!=kol[0])
  {cout<<"NO"; return 0; }

cout<<"YES"<<endl;



    return 0;
}