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

const int maxn=2e5+10,inf=1e9 + 10;

int a[maxn];
pii p[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m; cin>>n>>m;

    for(int i=0;i<n;i++)
	cin>>a[i];
    for(int i=0;i<m;i++)
	cin>>p[i].F>>p[i].S;
    sort(p,p+m);
    for(int i=1;i<m;i++)
	p[i].S+=p[i-1].S;
    for(int i=0;i<n;i++){
	int id=lower_bound(p,p+m, (pii){a[i],inf})-p-1;
	if(id==-1) cout<<0<<" ";
	else cout<<p[id].S<<" ";
    }
    
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")