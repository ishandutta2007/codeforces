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
	BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n, m;
		cin>>n>>m;
		vi V(n);
		for(int &i:V)cin>>i;
		vector<ll> V2;
		V2.pb(0);
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			V[i]-=x;
			V2.pb(V2.back()+V[i]);
		}
		vii Q;
		vi Q2;
		vector<vector<int>> co(n+1);
		set<int> S;
		vector<int> todo, vis(n+1);
		for(int i=0; i<=n; i++){
			if(V2[i])S.insert(i);
			else todo.pb(i);
		}
		while(m--){
			int l, r;
			cin>>l>>r;
			co[l-1].push_back(Q.size());
			co[r].pb(Q.size());
			Q.push_back({l-1, r});
		}
		while(S.size()){
			//cout<<"a";
			for(int i:todo){
				vis[i]=1;
				for(int j:co[i]){
					if(vis[Q[j].st] && vis[Q[j].nd])Q2.pb(j);
				}
			}
			todo.clear();
			if(!Q2.size())break;
			for(auto j:Q2){
				auto it=S.lower_bound(Q[j].st);
				vi todo2;
				while(it!=S.end() && *it<=Q[j].nd){
					todo.pb(*it);
					todo2.pb(*it);
					it++;
					//cout<<"a";
				}
				for(int i:todo2){
					S.erase(S.find(i));
				}
			}
			Q2.clear();
		}
		if(S.size())cout<<"NO\n";
		else cout<<"YES\n";
	}
}