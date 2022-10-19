#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("trapv")
#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=3e5+5, K=18, mod=1e9+7, INF=1e9+5;
ll pot(ll a, ll b){
    if(b==0) return 1ll;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*pot(a, b&1))%mod;
}
void solve(){
	int n;
	cin>>n;
	vi V(n);
	for(int i=0; i<n; i++)cin>>V[i];
	sort(all(V));
	int res=0;
	for(int i=0; i<n; i++){
		auto it=upper_bound(all(V), V[i]);
		int ans=it-V.begin()-i;
		int d=(*it)-V[i];
		while(it!=V.end()){
			auto it2=lower_bound(all(V), 2*(*it)-V[i]);
			ans++;
			it=it2;
		}
		res=max(res, ans);
	}
	cout<<n-res<<"\n";

}
int main(){
	BOOST;
	int t=1;
	cin>>t;
	while(t--)solve();
}