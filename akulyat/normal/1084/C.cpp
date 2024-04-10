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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
cin>>s;
s+='b';
ll ans=1;
ll counter=0;
for (auto i:s)
  {
  if (i=='b')
    ans*=counter+1, ans%=mod, counter=0;
  if (i=='a')
    counter++;
  }
ans--;
ans+=mod;
ans%=mod;
cout<<ans<<endl;



    return 0;
}