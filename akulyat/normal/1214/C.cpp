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


ll n,i,j, sum;
vector <ll> m;
string s;
bool viv=false;

void bad()
{
cout<<"No";
exit(0);
}

void make()
{
ll cur=0;
for (ll i=0; i<n; i++)
  {
  if (s[i]=='(')
    m.push_back(1);
  else
    m.push_back(-1);
  cur+=m.back();
  if (cur<-1)
    bad();
  }
for (auto i:m)
  sum+=i;
if (sum)
  bad();
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
make();
cout<<"Yes"<<endl;





    return 0;
}