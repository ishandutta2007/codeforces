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
int r[N], c[N];
int find(int v){
	if(r[v]==v)return v;
	return r[v]=find(r[v]);
}
multiset<int> S;
int ile=1;
void Union(int u, int v){
	v=find(v);
	u=find(u);
	if(u==v){
		ile++;
		return;
	}
	S.erase(S.find(-c[u]));
	S.erase(S.find(-c[v]));
	c[u]+=c[v];
	r[v]=u;
	S.insert(-c[u]);
}
void solve(){
	int n, d;
	cin>>n>>d;
	for(int i=1; i<=n; i++){
		S.insert(-1);
		c[i]=1;
		r[i]=i;
	}
	for(int i=0; i<d; i++){
		int u, v;
		cin>>u>>v;
		Union(u, v);
		auto it=S.begin();
		int k=*it;
		for(int j=1; j<ile; j++){
			it++;
			k+=*it;
		}
		cout<<-k-1<<"\n";
	}
}
int main(){
	BOOST;
	int t=1;
	//cin>>t;
	while(t--)solve();
}