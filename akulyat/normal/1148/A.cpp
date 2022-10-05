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
ll a, b, c;
cin>>a>>b>>c;
ll ans=0;
ans+=2*c;
ll k=min(a, b);
ans+=2*k;
a-=k;
b-=k;
if (a||b)
  ans++;
cout<<ans;




    return 0;
}