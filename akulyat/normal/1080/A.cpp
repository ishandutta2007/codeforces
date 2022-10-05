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
ll k;
cin>>n>>k;
ll a=2*n, b=5*n, c=8*n;
ll ans=0;
ans+=(a-1)/k+1;
ans+=(b-1)/k+1;
ans+=(c-1)/k+1;
cout<<ans;
    return 0;
}