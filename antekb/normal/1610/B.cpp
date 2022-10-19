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

const int N=3e5+5, K=18, mod=998244353, INF=1e9+5;
void solve(){
	int n;
	cin>>n;
	vi V(n);
	for(int &i:V)cin>>i;
	int a, b;
	bool c=0;
	for(int i=0; i<n; i++){
		if(V[i]!=V[n-1-i]){
			c=1;
			a=V[i];
			b=V[n-1-i];
		}
	}
	if(c==0){
		cout<<"YES\n";
		return;
	}
	vi V2, V3;
	for(int i=0; i<n; i++){
		if(V[i]!=a)V2.pb(V[i]);
		if(V[i]!=b)V3.pb(V[i]);
	}
	c=0;
	for(int i=0; i<V2.size(); i++){
		if(V2[i]!=V2[V2.size()-1-i]){
			c=1;
		}
	}
	if(c==0){
		cout<<"YES\n";
		return;
	}
	c=0;
	for(int i=0; i<V3.size(); i++){
		if(V3[i]!=V3[V3.size()-1-i]){
			c=1;
		}
	}
	if(c==0){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}
int main(){
	BOOST;
	int t=1;
	cin>>t;
	while(t--)solve();
}