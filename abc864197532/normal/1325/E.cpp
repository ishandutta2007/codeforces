#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, NN = 1000001, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

set <int> adj[N];

vector <int> prime_id(NN, -1), prime;
int id = 1;

void build () {
	fop (i,2,NN) {
		if (prime_id[i] == -1) {
			prime_id[i] = id++;
			prime.pb(i);
			for (int j = i + i; j < NN; j += i) prime_id[j] = 0;
		}
	}
}

int bfs(int v) {
	queue <int> q;
	vector <int> dis(id, -1);
	q.push(v);
	dis[v] = 0;
	int ans = x;
	while (q.size()) {
		int v = q.front(); q.pop();
		for (int u : adj[v]) {
			if (~dis[u] && dis[v] <= dis[u]) {
				ans = min(ans, dis[u] + dis[v] + 1);
			} else if (dis[u] == -1) {
				dis[u] = dis[v] + 1;
				q.push(u); 
			}
		}
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	build();
	int n, tmp, ans = x;
	cin >> n;
	fop (i,0,n) {
		cin >> tmp;
		vector <int> f(2);
		int now = 0;
		for (int j = 0; prime[j] * prime[j] <= tmp; ++j) {
			if (tmp % prime[j] == 0) {
				f[now] = j + 1;
				int cnt = 0;
				while (tmp % prime[j] == 0) tmp /= prime[j], cnt++;
				if (cnt % 2 == 0) f[now] = 0;
				now++;
			}
		}
		if (tmp > 1) f[now++] = prime_id[tmp];
		if (now == 1) f[now++] = 0;
		if (f[0] == 0 && f[1] == 0) {
			ans = min(ans, 1);
		}
		if (adj[f[0]].count(f[1])) {
			ans = min(ans, 2);
		}
		adj[f[0]].insert(f[1]);
		adj[f[1]].insert(f[0]);
	}
	for (int j = 1; prime[j - 1] <= 1000; ++j) {
		ans = min(ans, bfs(j));
	}
	if (ans == x) ans = -1;
	cout << ans << endl;
}