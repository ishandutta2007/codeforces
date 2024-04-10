#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 100;
const int block = 320;

class query {
	public:
		int left;
		int right;
		int idx;
		bool operator < (query &other) {
			if (left / block != other.left / block)
				return left < other.left;
			int k = left / block;
			if (k & 1)
				return right < other.right;
			else
				return right > other.right;
		}
};

bool compare (query fi, query se) { return fi < se; }

query q[maxn];

int n, c[maxn];
vector <int> t[maxn];

set <pair <ll, ll> > s;

int Time = 1, per[maxn], st[maxn], ft[maxn];
void dfs (int v, int par = -1) {
	per[Time] = v;
	st[v] = Time ++;
	for (auto w : t[v])
		if (w != par)
			dfs (w, v);
	ft[v] = Time;
}

ll dp[maxn], pd[maxn];
ll get () { 
	auto it = (*s.begin()).F;
	it *= -1;
	return pd[it];
}

void add (int x) {
	s.erase ({-dp[x], x});
	pd[dp[x]] -= x;
	dp[x] ++;
	pd[dp[x]] += x;
	s.insert ({-dp[x], x});
}

void del (int x) {
	s.erase ({-dp[x], x});
	pd[dp[x]] -= x;
	dp[x] --;
	pd[dp[x]] += x;
	if (dp[x] != 0) 
		s.insert ({-dp[x], x});
}

ll ans[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n - 1; i++) {
		int v, u;
		cin >> v >> u;
		t[v].PB (u);
		t[u].PB (v);
	}
	
	dfs (1);
	
	for (int i = 1; i <= n; i++) {
		q[i].left = st[i], q[i].right = ft[i];
		q[i].idx = i;
	}
	sort (q + 1, q + n + 1, compare);
	
	int L = 1, R = 1;
	for (int i = 1; i <= n; i++) {
		int l = q[i].left, r = q[i].right;
		while (R < r) {
			add (c[per[R]]);
			R ++;
		}
		while (L > l) {
			L --;
			add (c[per[L]]);
		}
		while (R > r) {
			R --;
			del (c[per[R]]);
		}
		while (L < l) {
			del (c[per[L]]);
			L ++;
		}
		ans[q[i].idx] = get ();
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}