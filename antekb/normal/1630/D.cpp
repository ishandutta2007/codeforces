#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("trapv")
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
 
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const int N=3e5+5, INF=1e9+5;
//const int mod=998244353;
const int mod=1e9+7;
ll prob(int k, vi V){
		int n=V.size();
		ll ans=0;
		for(int j=0; j<k; j++){
			int m=INF;
			int ile=0;
			for(int i=j; i<n; i+=k){
				if(V[i]<0)ile++;
				m=min(m, abs(V[i]));
				ans+=abs(V[i]);
			}
			if(ile&1)ans-=2*m;
		}
		return ans;
}
int main(){
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n, m;
		cin>>n>>m;
		vi V(n);
		for(int &i:V)cin>>i;
		int k=0;
		while(m--){
			int x;
			cin>>x;
			k=__gcd(k, x);
		}
		ll ans=prob(k, V);
		for(int i=0; i<k; i++)V[i]=-V[i];
		ans=max(ans, prob(k, V));
		cout<<ans<<"\n";
	}
}