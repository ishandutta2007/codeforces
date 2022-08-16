#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, par[N], w[N];
vector <int> adj[N], v;
int st[N][LEVEL], mx[N][LEVEL], level[N];

void dfs(int x, int p) {
	v.pb(x);
	for (auto it : adj[x]){
		if (it == p) continue;
		level[it] = level[x] + 1;
		dfs(it, x);
	}
}

void clearall() {
	for (int i = 1; i <= n; i++) {
		for (ll j = 0; j < LEVEL; j++) st[i][j] = -1, mx[i][j] = 0;
	}
}

void fillst(int root) {
	v.clear();
	dfs(root, 0);
	for (int j = 0; j < LEVEL; j++) {
		for (auto i : v) {
			if (j == 0 && i != root) {
				st[i][j] = par[i];
				mx[i][j] = w[i];
			} 
			if (j != 0 && st[i][j - 1] != -1) {
				st[i][j] = st[st[i][j - 1]][j - 1];
				mx[i][j] = max(mx[i][j - 1], mx[st[i][j - 1]][j - 1]);
			}
		}
	}
}

int kth(int x, int y, int k){
	int mxx = 0;
	for (int i = LEVEL - 1; i >= 0; i--){
		if (k >= (1 << i)){
			mxx = max(mxx, mx[x][i]);
			x = st[x][i];
			if (x == -1) return INFi;
			k -= (1 << i);
		}
	}
	if (x != y) return INFi;
	return mxx;
}

bool check(int y, int x, int mx) {
	return kth(x, y, level[x] - level[y]) <= mx;
}

void solve() {
	cin >> n >> m;
	vector <pair <int, int>> Q, doc;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> z;
		if (z == 1) {
			cin >> x >> y;
			adj[y].pb(x);
			par[x] = y;
			w[x] = i;
		} else if (z == 2) {
			cin >> x;
			doc.pb({i, x});
		} else {
			cin >> x >> y;
			Q.pb({x, y - 1});
		}
	}

	clearall();
	for (int i = 1; i <= n; i++) {
		if (par[i] == 0) fillst(i);
	}

	for (auto &[x, y] : Q) {
		bool ans = check(x, doc[y].s, doc[y].f);
		cout << (ans == 1? "YES\n" : "NO\n");
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}