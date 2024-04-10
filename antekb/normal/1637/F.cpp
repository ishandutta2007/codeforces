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
vi E[N];
int tab[N];
pair<int, ll> dfs(int v, int p){
	ll sum=0;
	int m=0, m2=0;
	for(int u:E[v]){
		if(u!=p){
			auto a=dfs(u, v);
			sum+=a.nd;
			if(a.st>m)m2=m, m=a.st;
			else if(a.st>m2)m2=a.st;
		}
	}
	if(p==-1){
		sum+=tab[v]-m;
		sum+=tab[v]-m2;
	}
	else{
		if(tab[v]>m){
			sum+=tab[v]-m;
			m=tab[v];
		}
	}
	return mp(m, sum);
}
int main(){
	BOOST;
	int n;
	cin>>n;
	int opt=0;
	for(int i=1; i<=n; i++){
		cin>>tab[i];
		if(tab[i]>=tab[opt])opt=i;
	}
	for(int i=1; i<n; i++){
		int u, v;
		cin>>u>>v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	//E[opt].push_back(0);
	//E[0].push_back(opt);
	auto a=dfs(opt, -1);
	cout<<a.nd;
}