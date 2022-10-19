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
 
const int N=2e5+5, INF=1e9+5, mod=1e9+7;
int main(){
	
	//BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vi V(n);
		vector<vi> E(n+2);
		for(int i=0; i<n; i++){
			cin>>V[i];
			E[V[i]].pb(i+1);
		}
		bool b=1;
		if(E[0].size())b=0;
		vi V2, V3;
		V2.pb(0);
		V2.pb(n+1);
		vi ans;
		int ile=0;
		while(V2.size() || V3.size()){
			for(int i:V2){
				for(int j:E[i])V3.pb(j);
			}
			for(int &i:V3)if(E[i].size())swap(i, V3.back());
			for(int i:V3)ans.pb(i);
			if(b)ile+=V3.size();
			b^=1;
			V2=V3;
			V3.clear();
		}
		cout<<ile<<"\n";
		for(int i:ans)cout<<i<<" ";
		cout<<"\n";
	}
}