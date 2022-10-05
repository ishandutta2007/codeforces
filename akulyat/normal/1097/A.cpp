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
vector <string> m;
bool viv=false;
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n=5;
for (i=0; i<n; i++)
  {
  string a;
  cin>>a;
  if (a[0]==s[0]||a[1]==s[1])
    {
    cout<<"YES";
    return 0;
    }
  }
cout<<"NO"<<endl;





    return 0;
}