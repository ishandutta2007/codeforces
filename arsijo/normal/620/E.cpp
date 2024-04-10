#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 5e5;
vector<int> vec[MAX], v;
int first[MAX], last[MAX];

void dfs(int pos, int from = -1){
	first[pos] = (int) v.size();
	v.push_back(pos);
	for(int i = 0; i < (int) vec[pos].size(); i++){
		if(vec[pos][i] != from){
			dfs(vec[pos][i], pos);
		}
	}
	last[pos] = (int) v.size() - 1;
}

struct segment_tree{
private:
	ll *t, *y, n, *ar;
	void build(int v, int l, int r){
		y[v] = 0;
		if(l == r)
			return void(t[v] = ar[l]);
		int x = (l + r) >> 1;
		build(v << 1, l, x);
		build(v << 1 | 1, x + 1, r);
		t[v] = t[v << 1] | t[v << 1 | 1];
	}
	void push(int v){
		if(y[v]){
			y[v << 1] = y[v << 1 | 1] = t[v << 1] = t[v << 1 | 1] = y[v];
			y[v] = 0;
		}
	}
	void update(int v, int tl, int tr, int l, int r, ll val){
		if(l <= tl && tr <= r){
			y[v] = val;
			t[v] = val;
			return;
		}
		if(tr < l || r < tl)
			return;
		push(v);
		int x = (tl + tr) >> 1;
		update(v << 1, tl, x, l, r, val);
		update(v << 1 | 1, x + 1, tr, l, r, val);
		t[v] = t[v << 1] | t[v << 1 | 1];
	}
	ll get(int v, int tl, int tr, int l, int r){
		if(l <= tl && tr <= r)
			return t[v];
		if(tr < l || r < tl)
			return 0;
		push(v);
		int x = (tl + tr) >> 1;
		return get(v << 1, tl, x, l, r) | get(v << 1 | 1, x + 1, tr, l, r);
	}
public:
	segment_tree(int n, ll *ar){
		this->n = n;
		this->ar = ar;
		t = new ll[n << 2];
		y = new ll[n << 2];
		build(1, 0, n - 1);
	}
	ll get(int l, int r){
		return get(1, 0, n - 1, l, r);
	}
	void update(int l, int r, ll val){
		update(1, 0, n - 1, l, r, val);
	}
};

ll _count(ll n){
	ll ans = 0;
	do{
		ans += n & 1;
	}while(n >>= 1);
	return ans;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(0);

	assert((int) v.size() == n);

	ll t[n];
	for(int i = 0; i < (int) v.size(); i++){
		t[i] = (1LL << ar[v[i]]);
	}

	segment_tree tree(n, t);

	while(m--){
		int k;
		cin >> k;
		if(k == 1){
			int v, c;
			cin >> v >> c;
			v--;
			tree.update(first[v], last[v], (1LL << c));
		}else{
			int v;
			cin >> v;
			v--;
			ll res = tree.get(first[v], last[v]);
			cout << _count(res) << endl;
		}
	}

}