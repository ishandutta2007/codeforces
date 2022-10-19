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

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=3e5+5, INF=1e9+5, mod=1e9+7;
set<pii> S;
int main(){
	BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n, m;
		cin>>n>>m;
		int K=1000;
		map<int, int> M;
		vi V(n);
		for(int &i:V)cin>>i, M[i]++;
		S.clear();
		while(m--){
			int x, y;
			cin>>x>>y;
			S.insert({y,x});
			S.insert({x,y});
		}
		vector<vi> V2(K);
		vii V3;
		vi V4=V;
		sor(V4);
		V4.resize(unique(all(V4))-V4.begin());
		ll ans=0;
		for(auto i:M){
			if(i.nd>=K){
				int j=i.st;
				for(int k:V4){
					if(k!=j && S.find(mp(k,j))==S.end()){
						ans=max(ans, (M[k]+i.nd)*1ll*(k+j));
					}
				}
			}
			else{
				V2[i.nd].pb(i.st);
				V3.pb(i);
			}
		}
		for(pii i:V3){
			for(int j=1; j<=i.nd; j++){
				for(int k=V2[j].size()-1; k>=0; k--){
					if(i.st!=V2[j][k] && S.find(mp(i.st, V2[j][k]))==S.end()){
						ans=max(ans, (i.nd+j)*1ll*(i.st+V2[j][k]));
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}