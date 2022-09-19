#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mkp make_pair
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " -> " << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const int Maxn = 2e3 + 10;
const int N = (4 * Maxn) + 10;
const int Log = 42;
const ll Inf = 1e18 + 10;

vector<int> G[N], H[N], top;

int n, mk[N], C[N];

void DFS(ll u){
	mk[u] = 1;
	for(auto adj : G[u]) if(!mk[adj]) DFS(adj);
	top.pb(u);
}
void DFS(ll u, ll co){
	C[u] = co;
	mk[u] = 1;
	for(auto adj : H[u]) if(!mk[adj]) DFS(adj, co);
}
vector<int> ans;

bitset<N> E[N];

void add_edge(ll u, ll v){
	if(E[u][v]) return ;
	E[u][v] = 1;
	G[u].pb(v);
	H[v].pb(u);
}
ll rev(ll x){
	if(x < n + n) return x + n + n;
	else return x - n - n;
}
void add(ll a, ll b){
	//cerr << a << ' ' << b << '\n';
	add_edge(rev(a), b);
	add_edge(rev(b), a);
}

bool check(){
	memset(mk, 0, sizeof mk);
	for(int i = 0; i < 4 * n; i++) if(!mk[i]) DFS(i);
	memset(mk, 0, sizeof mk);
	memset(C, 0, sizeof C);
	
	reverse(all(top));
	int cnt = 1;
	for(auto x : top) if(!mk[x]) DFS(x, ++cnt);
	//cerr << cnt << '\n';
	for(int i = 0; i < n + n; i++) if(C[i] == C[rev(i)]) {
		//cerr << "! " << i << ' ' << C[i] << '\n'; 
		return false;
	}
	memset(mk, 0, sizeof mk);
	reverse(all(top));
	for(auto x : top){
		if(x < n + n && !mk[rev(x)]){
			ans.pb(x);
		}
		mk[x] = 1;
	}
	
	return true;
}



string A[Maxn], B[Maxn], pat;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < n; i++) cin >> B[i];
	cin >> pat;
	
	
	int a, b, c, d;
	for(int i = 0; i < n; i++){
		for(int jj = 0; jj < n; jj++){
			a = A[i][jj] - '0';
			b = B[i][jj] - '0';
			
			c = pat[jj] - '0';
			d = pat[i] - '0';
			int j = n + jj;
			if(c == 0 && d == 0){
				if(a == b) continue;
				return cout << -1, 0;
			}
			if(c == 1 && d == 0){
				if(a == b){
					add(rev(i), j);
					add(rev(i), rev(j));
				} else {
					add(i, j);
					add(i, rev(j));
				}
			}
			if(c == 0 && d == 1){
				if(a == b){
					add(rev(j), i);
					add(rev(j), rev(i));
				} else {
					add(j, i);
					add(j, rev(i));
				}
			}
			if(c == 1 && d == 1){
				if(a == b){
					add(i, rev(j));
					add(rev(i), j);
				} else {
					add(i, j);
					add(rev(i), rev(j));
				}
			}
		}
	}
	//cerr << "sal" << '\n';
	if(!check()) return cout << -1, 0;
	cout << ans.size() << '\n';
	for(auto x : ans) cout << (x < n ? "row " : "col ") << x % n << '\n';
	return 0;
}