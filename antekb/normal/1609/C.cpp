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

const int N=1e6+5, K=18, mod=1e9+7, INF=1e9+5;
int sito[N];
ll solve2(vector<int> V){
	int n=V.size();
	vi l(n+1), r(n+1);
	for(int i=0; i<n; i++){
		if(V[i]==1){
			l[i+1]=l[i]+1;
		}
	}
	for(int i=n-1; i>=0; i--){
		if(V[i]==1){
			r[i]=r[i+1]+1;
		}
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		if(sito[V[i]]==0){
			ans+=(l[i]+1)*1ll*(1+r[i+1])-1;
		}
	}
	return ans;
}
void solve(){
	int n, e;
	cin>>n>>e;
	vector<vi> V(e);
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		V[i%e].pb(x);
	}
	ll ans=0;
	for(int i=0; i<e; i++)ans+=solve2(V[i]);
	cout<<ans<<"\n";
}
int main(){
	sito[1]=1;
	for(int i=2; i<N; i++){
		if(!sito[i]){
			for(int j=i; j<=(N-1)/i; j++){
				sito[j*i]=1;
			}
		}
	}
	BOOST;
	int t=1;
	cin>>t;
	while(t--)solve();
}