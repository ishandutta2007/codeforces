#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

ll dis[maxn];
vector<pair<int, ll> > t[maxn];
int par[maxn], st[maxn], ft[maxn], fen[maxn], n;

void add(int idx, int val){
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += val;
}

int get(int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

int Time = 1;
void DFS(int v, int p = -1){
	st[v] = Time ++;
	for (auto u : t[v])
		if (u.first != p)
			DFS(u.first, v);
	ft[v] = Time;
}

void dfs(int v, int p = -1, ll untilnow = 0){
	dis[v] = max(dis[v], untilnow);
	par[v] = p;
	for (auto u : t[v])
		if (u.first != p)
			dfs(u.first, v, untilnow + u.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int v, u;
		ll w;
		scanf("%d%d%lld", &v, &u, &w);
		t[v].push_back({u, w});
		t[u].push_back({v, w});
	}
	dfs(1);
	int fi = max_element(dis + 1, dis + n + 1) - dis;
	dfs(fi);
	int se = max_element(dis + 1, dis + n + 1) - dis;
	par[se] = -1;
	dfs(se);
	while (dis[fi] > dis[par[fi]])
		fi = par[fi];
	DFS(fi);
	vector<pair<ll, pair<int, int> > > dists;
	for (int v = 1; v <= n; v++)
		dists.push_back({dis[v], {st[v], v}});
	sort(dists.begin(), dists.end());
	
	int q;
	scanf("%d", &q);
	while (q --){
		ll x;
		scanf("%lld", &x);
		memset(fen, 0, sizeof fen);
		int ptr = n - 1;
		int answer = 0;
		for (int i = n - 1; i >= 0; i--){
			int v = dists[i].second.second;
			add(st[v], +1);
//			cout << "Added : " << v << endl;
			while (dists[ptr].first - dis[v] > x){
				int u = dists[ptr].second.second;
				add(st[u], -1);
//				cout << "Deleted : " << v << endl;
				ptr --;
			}
			answer = max(answer, get(ft[v] - 1) - get(st[v] - 1));
		}
		printf("%d\n", answer);
	}
	return 0;
}