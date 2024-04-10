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
set <char> glas;
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
glas.insert('a');
glas.insert('e');
glas.insert('u');
glas.insert('i');
glas.insert('o');
cin>>s;
n=s.size();
vector <bool> p;
p.push_back(false);
p.push_back(false);
for (i=2; i<n; i++)
  {
  if (!p[i-1])
    if (s[i]!=s[i-1]||s[i-2]!=s[i-1]||s[i]!=s[i-2])
      if (glas.find(s[i])==glas.end())
        if (glas.find(s[i-1])==glas.end())
          if (glas.find(s[i-2])==glas.end())
            p.push_back(true);
  if (p.size()==i)
    p.push_back(false);
  }
string ans;
for (i=0; i<n; i++)
  {
  if (p[i])
    ans+=' ';
  ans+=s[i];
  }
cout<<ans<<endl;


    return 0;
}