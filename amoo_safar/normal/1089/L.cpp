// Remember...

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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn], b[maxn];
bool is[maxn];
vector<int> vec;
vector<int> v[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,k; cin>>n>>k;
    int CNT=k;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(is[a[i]]==0)
	    is[a[i]]=1, CNT--;
    }
    for(int i=0;i<n;i++){
	cin>>b[i];
	v[ a[i] ].PB(b[i]);
    }
    for(int i=1;i<=k;i++){
	if(v[i].empty()) continue;
	sort(v[i].begin(), v[i].end());
	v[i].pop_back();
	for(int x:v[i])
	    vec.PB(x);
    }
    sort(vec.begin(), vec.end());
    ll ans=0;
    for(int i=0;i<CNT;i++){
	ans+= vec[i];
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")