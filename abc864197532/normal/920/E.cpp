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

struct Dsu {
	int n;
	vector <int> dsu, size;
	Dsu (int n): n(n) {
		dsu.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
			size[i] = 1;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		if (size[x] > size[y]) {
			dsu[x] = y;
			size[y] += size[x];
			size[x] = 0;
		} else {
			dsu[y] = x;
			size[x] += size[y];
			size[y] = 0;
		}
		return true;
	}
};

vector <set <int>> adj;

int main () {
    int n, m, u, v;
    cin >> n >> m;
    adj.resize(n);
    fop (i,0,m) {
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    Dsu dsu(n);
    set <int> heavy;
    fop (i,0,n) {
        if (adj[i].size() < n / 2) heavy.insert(i);
    }
    int p = *heavy.begin();
    for (int i : heavy) {
        if (i == p) continue;
        dsu.Union(i, p);
    }
    fop (i,0,n) {
        if (heavy.count(i)) heavy.erase(i);
        else heavy.insert(i);
    }
    for (int k : heavy) {
        fop (i,0,n) {
            if (!adj[k].count(i)) dsu.Union(k, i);
        }
    }
    vector <int> ans;
    fop (i,0,n) {
        if (dsu.Find(i) == i) ans.pb(dsu.size[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
}