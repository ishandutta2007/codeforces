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
string s;

int main()
{
cin>>n;
cin>>s;
sort(s.begin(), s.end());
for (i=1; i<n; i++)
  if (s[i]==s[i-1])
    {
    cout<<"Yes"<<endl;
    return 0;
    }
if (n==1)
    {
    cout<<"Yes"<<endl;
    return 0;
    }

cout<<"No";

    return 0;
}