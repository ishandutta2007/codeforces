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


ll n,i,j,ans,k1,k2,k;
vector <ll> m;
bool viv=false;

void work(ll pl)
{
ll lk1=k1;
ll lk2=k2;
while (pl<n)
  {
  if (m[pl]==1)
    lk1--;
  else
    lk2--;
  pl+=k;
  }
ans=max(ans, abs(lk1-lk2));
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  if (a==1)
    k1++;
  else
    k2++;
  m.push_back(a);
  }
for (ll i=0; i<k; i++)
  work(i);
cout<<ans<<endl;




    return 0;
}