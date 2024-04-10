#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU
{
	int n; vector<int> a;
    DSU(int _n) { n = _n; a.resize(n+1); for (int i = 0; i <= n; ++i) a[i] = i; }
    int root(int x) { return (x == a[x]) ? x : a[x] = root(a[x]); }
    int same(int x, int y) { return root(x) == root(y); }
    void merge(int x, int y) { a[root(x)] = root(y); }
};

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

//    vector< vector<int> > g(n+1);
//    for (int i = 1; i <= n; ++i) {
//        g[i].push_back(i);
//        g[p[i]].push_back(i);
//    }

	int ans = 0;

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i] == i) root = i;
    }

    DSU dsu(n);
    for (int i = 1; i <= n; ++i) {
        if (root == i) continue;
        if (dsu.same(i, p[i])) {
			if (root == 0) root = i;
            p[i] = root;
            ++ans;
        } else dsu.merge(i, p[i]);
    }

    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
    }
    cout << endl;
}