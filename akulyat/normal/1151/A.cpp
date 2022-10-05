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


ll n,i,j, ans;
vector <ll> m;
bool viv=false;
string s;

void solve(ll pl)
{
string t="ACTG";
ll lans=0;
for (ll i=0; i<4; i++)
  {
  ll k=s[pl+i]-t[i];
  while (k<0)
    k+=26;
  if (k>13)
    k=26-k;
  lans+=k;
  }
ans=min(ans, lans);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
ans=inf;
for (ll i=0; i<n-3; i++)
  solve(i);
cout<<ans<<endl;



    return 0;
}