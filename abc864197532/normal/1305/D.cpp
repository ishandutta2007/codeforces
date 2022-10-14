#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 1000;

set <int> adj[N];

int main () {
	int n, u, v, tmp;
	cin >> n;
	fop (i,0,n - 1) {
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	set <int> leaf;
	fop (i,0,n) if (adj[i].size() == 1) leaf.insert(i);
        vector <bool> vis(n, false);
	while (leaf.size() > 1) {
		u = *leaf.begin(); leaf.erase(leaf.begin());
		v = *leaf.begin(); leaf.erase(leaf.begin());
                vis[u] = vis[v] = true;
		cout << "? " << u + 1 << ' ' << v + 1 << endl;
		cin >> tmp;
		if (tmp == u + 1 || tmp == v + 1) {
			cout << "! " << tmp << endl;
			return 0;
		}
		for (int i : adj[v]) adj[i].erase(v);
		for (int i : adj[u]) adj[i].erase(u);
                adj[u].clear(); adj[v].clear();
		fop (i,0,n) if (!leaf.count(i) and adj[i].size() == 1) leaf.insert(i); 
	}
        fop (i,0,n) if(!vis[i]) leaf.insert(i);
	cout << "! " << *leaf.begin() + 1 << endl;
	return 0;
}