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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, w[N];
map <vector<int>, int> ct;

template<typename T>
struct trie {
	int n;
	stack <int> s;
	vector <T> trie_node;

	trie(int n) : n(n) {
		for (int i = n - 1; i >= 1; i--) s.push(i);
		trie_node.resize(n);
	}

	void insert(vector <int> &a, int i = 0, int v = 0) {
		if (i == a.size()) {
			trie_node[v].cnt++;
			return;
		}
		int k = a[i];
		if (trie_node[v].go.find(k) == trie_node[v].go.end()) {
			trie_node[v].go[k] = s.top();
			s.pop();
		}
		insert(a, i + 1, v);
		insert(a, i + 1, trie_node[v].go[k]);
	}

	void remove(vector <int> &a, int i = 0, int v = 0) {
		if (i == a.size()) {
			trie_node[v].cnt--;
			return;
		}
		remove(a, i + 1, v);
		remove(a, i + 1, trie_node[v].go[a[i]]);
	}
	
	int dfs(vector <int> &a, int i = 0, int v = 0, bool f = 0) {
		if (i == a.size()) {
			if (v == 0) return 0;
			if (f) return trie_node[v].cnt;
			return -trie_node[v].cnt;
		}
		return dfs(a, i + 1, v, f) + dfs(a, i + 1, trie_node[v].go[a[i]], 1 - f);
	}
};

struct node {
	map <int, int> go;
	int cnt = 0;
};

void solve() {
	cin >> n >> m;
	vector <vector <int>> a(n, vector <int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
		sort(all(a[i]));
		cin >> w[i];
	}
	vector <int> ind(n);
	iota(all(ind), 0);
	sort(all(ind), [&](int i, int j) {
		return w[i] < w[j];
	});
	
	trie <node> t(50 * n);

	vector <int> v;
	int ans = INFi;

	for (int i = 0; i < n; i++) t.insert(a[ind[i]]);

	for (int i = 0, j = n - 1; i < j; i++) {
		t.remove(a[ind[i]]);
		if (t.dfs(a[ind[i]]) == j - i) continue;
		while (j >= i && t.dfs(a[ind[i]]) != j - i) {
			t.remove(a[ind[j--]]);
		}
		if (i > j) break;

		t.insert(a[ind[++j]]);
		ans = min(ans, w[ind[i]] + w[ind[j]]);
	}

	if (ans == INFi) ans = -1;
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}