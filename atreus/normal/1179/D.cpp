// alaki centroid nazanim
// yad begirim tamiz CHT bezanim
// baraye debug goshad nabashim
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 10;
const ll inf = 1e18;

int n;
vector<int> t[maxn];
ll sz[maxn], dp[maxn], answer = inf;

struct line{
	ll a;
	ll b; // y = ax + b
	line(ll a_ = 0, ll b_ = 0){
		a = a_;
		b = b_;
	}
	ll get_y(ll x){
		return a * x + b;
	}
	ll intersect(line other){
		return (a - other.a) / (other.b - b);
	}
};

struct convex_hull_trick{
	queue<line> Q;
	void add(line l){
		while (Q.size() > 1){
			line last = Q.back();
			Q.pop();
			line now = Q.back();
			if (now.intersect(last) < now.intersect(l)){
				Q.push(last);
				break;
			}
		}
		Q.push(l);
	}
	ll get(ll x){
		if (Q.empty())
			return inf;
		while (Q.size() > 1){
			line last = Q.back();
			Q.pop();
			if (last.get_y(x) < Q.back().get_y(x)){
				Q.push(last);
				break;
			}
		}
		return Q.back().get_y(x);
	}
	void vitex(){
		while (!Q.empty())
			Q.pop();
	}
} CHT;

bool compare_size(int v, int u){ return sz[v] < sz[u]; }

void dfs(int v, int par = -1){
	sz[v] = 1;
	for (auto u : t[v]){
		if (u != par){
			dfs(u, v);
			sz[v] += sz[u];
			answer = min(answer, dp[u] + (n - sz[u]) * (n - sz[u] - 1) / 2);
		}
	}
	dp[v] = 1ll * sz[v] * (sz[v] - 1) / 2;
	sort(t[v].begin(), t[v].end(), compare_size);
	for (auto u : t[v]){
		if (u == par)
			continue;
		ll me = n - sz[u];
		ll cnst = dp[u] + me * (me - 1) / 2;
		answer = min(answer, cnst + CHT.get(me));
		CHT.add(line(-sz[u], dp[u] + 1ll * sz[u] * (sz[u] + 1) / 2));
		dp[v] = min(dp[v], dp[u] + 1ll * (sz[v] - sz[u]) * (sz[v] - sz[u] - 1) / 2);
	}
	CHT.vitex();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	cout << 1ll * n * (n - 1) - answer << '\n';
}