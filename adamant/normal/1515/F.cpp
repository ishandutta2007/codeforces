#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 7e5;

set<pair<int, int>, greater<pair<int, int>>> que;
int to[maxn], c[maxn], par[maxn];
vector<int> g[maxn], st[maxn];
int x;

int get(int v) {
    return par[v];
}

bool uni(int i) {
    int a = get(to[2 * i]);
    int b = get(to[2 * i + 1]);
    if(a == b || c[a] + c[b] - x < 0) {
        return false;
    } else {
        if(st[a].size() > st[b].size()) {
            swap(a, b);
        }
        c[b] += c[a] - x;
        for(auto it: st[a]) {
            par[it] = b;
            st[b].push_back(it);
        }
        st[a].clear();
        for(auto it: g[a]) {
            que.erase({c[get(to[it])] + c[get(to[it ^ 1])] - x, it / 2});
            to[it] = get(to[it]);
            to[it ^ 1] = b;
            g[b].push_back(it);
            que.insert({c[get(to[it])] + c[get(to[it ^ 1])] - x, it / 2});
        }
        g[a].clear();
        return true;
    }
}

void solve() {
    int n, m;
    cin >> n >> m >> x;
    iota(par, par + n, 0);
    for(int i = 0; i < n; i++) {
        st[i] = {i};
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to[2 * i] = v;
        to[2 * i + 1] = u;
        g[u].push_back(2 * i);
        g[v].push_back(2 * i + 1);
        que.insert({c[u] + c[v] - x, i});
    }
    vector<int> ans;
    while(!que.empty()) {
        int i = begin(que)->second;
        que.erase(begin(que));
        if(uni(i)) {
            ans.push_back(i + 1);
        }
    }
    if(st[get(0)].size() == n) {
        cout << "YES\n";
        for(auto it: ans) {
            cout << it << "\n";
        }
    } else {
        cout << "NO\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}