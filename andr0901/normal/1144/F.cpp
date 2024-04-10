#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;
vector <int> col;

int change(int cur) {
	if (cur == 1)
		return 2;
	return 1;
}

void dfs(int v, int cur) {
	cur = change(cur);
	col[v] = cur;
	for (auto u : gr[v]) {
		if (col[u] && col[u] == cur) 
			cout << "NO", exit(0);
		if (!col[u])
			dfs(u, cur);
	}
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    vector <pii> edges(m);
    forn (i, 0, m) {
    	int a, b;
    	cin >> a >> b;
    	a--, b--;
    	gr[a].pb(b), gr[b].pb(a);
    	edges[i] = {a, b};
    }
   	col.resize(n);
   	forn (i, 0, n)
   		if (!col[i])
   			dfs(i, 1);
    cout << "YES\n";
    for (auto i : edges) 
    	cout << col[i.fs] - 1;
    return 0;
}