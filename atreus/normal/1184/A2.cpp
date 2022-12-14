// High above the clouds there is a rainbow...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

bool b[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,ans=0; cin>>n;
    string s; cin>>s;
    for(int g=1;g<=n;g++){
	if(n%g==0){
	    memset(b,0,sizeof b);
	    for(int i=0;i<n;i++)
		b[i%g]^= s[i]=='1';
	    bool is=0;
	    for(int i=0;i<g;i++)
		is|= b[i];
	    if(is==0){
		for(int i=g;i<=n;i+=g){
		    if(__gcd(i,n)==g) ans++;
		}
	    }		
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")