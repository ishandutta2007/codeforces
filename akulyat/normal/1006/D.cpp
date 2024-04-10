#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <ll> m;
bool viv=false;
string s1,s2;

int main()
{
cin>>n>>s1>>s2;
ll ans=0;
if (n&1)
  if (s1[n/2]!=s2[n/2])
    ans++;

for (i=0; i<n/2; i++)
  {
  vector <char> st;
  st.push_back(s1[i]);
  st.push_back(s1[n-1-i]);
  st.push_back(s2[i]);
  st.push_back(s2[n-1-i]);
  ll kol=0;
  for (auto i:st)
    for (auto j:st)
      if (i==j)
        kol++;
  kol-=4;
  kol/=2;
  if (kol==3)
    ans++;
  if (kol==0)
    ans+=2;
  if (kol==1)
    {
    ans++;
    if ((s1[i]==s1[n-1-i])||(s1[i]==s1[n-1-i]))
      ans++;
    }
  }

cout<<ans;

    return 0;
}


/*
7
abacaba
aabacab

*/