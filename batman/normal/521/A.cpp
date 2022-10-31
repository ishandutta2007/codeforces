#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=301*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)2e9);
 
ll n,a[4];
string s;

 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='A')a[0]++;
    	if(s[i]=='G')a[1]++;
    	if(s[i]=='C')a[2]++;
    	if(s[i]=='T')a[3]++;
	}
	sort(a,a+4);
    if(a[3]!=a[2])return cout<<1,0;
    ll num=0;
    for(int i=0;i<4;i++)if(a[i]==a[3])num++;
    cout<<tavan(num,n,MOD);
    return 0;
}