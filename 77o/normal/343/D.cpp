#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e6 + 500;

vector<vector<int>> g;

int t[4 * N], u[4 * N];
bool marked[4 * N];

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

void change(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        u[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            change(v*2, tl, tm, pos, new_val);
        else
            change(v*2+1, tm+1, tr, pos, new_val);
        u[v] = max(u[v*2], u[v*2+1]);
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return u[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum(v*2, tl, tm, l, min(r, tm)), sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int timer = 1;
int tin[N], tout[N];

void dfs(int v) {
	tin[v] = timer++;
	for (int u : g[v]) {
		if (!tin[u]) {
			dfs(u);
		}
	}
	tout[v] = timer++;
}

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	int q;
	cin >> q;
	for (int it = 1; it <= q; it++) {
		int c, v;
		cin >> c >> v;
		v--;
		if (c == 1) {
			update(1, 0, timer, tin[v], tout[v], it);
		}
		if (c == 2) {
			change(1, 0, timer, tin[v], it);
		}
		if (c == 3) {
			cout << "01"[get(1, 0, timer, tin[v]) > sum(1, 0, timer, tin[v], tout[v])] << '\n';
		}
	}
    return 0;
}