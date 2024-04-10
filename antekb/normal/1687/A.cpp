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

template <typename H, typename T> 
ostream& operator<<(ostream& os, pair<H, T> m){
	return os <<"("<< m.st<<", "<<m.nd<<")";
}
template <typename H> 
ostream& operator<<(ostream& os, vector<H> V){
	os<<"{";
	for(int i=0; i<V.size(); i++){
		if(i)os<<" ";
		os<<V[i];
	}
	os<<"}";
	return os;
}

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

const int N=5e5+5, INF=1e9+5, mod=1e9+7;

int main(){
	//BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n, k;
		cin>>n>>k;
		vi V(n);
		for(int &i:V)cin>>i;
		if(k<n){
			ll s=0;
			ll ans=0;
			for(int i=0; i<k; i++)s+=V[i];
			ans=max(ans, s);
			for(int i=k; i<n; i++){
				s+=V[i];
				s-=V[i-k];
				ans=max(ans, s);
			}
			ans+=(k*ll(k-1))/2;
			cout<<ans<<"\n";
		}
		else{
			ll s=0;
			for(int i:V)s+=i;
			s+=n*ll(k);
			s-=(n*ll(n+1))/2;
			cout<<s<<"\n";
		}
	}
}