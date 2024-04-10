#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int MAX = 100007;
struct DSU
{
	int a[MAX];
    DSU() { for (int i = 0; i < MAX; ++i) a[i] = i; }
    int root(int x) { return a[x] == x ? x : a[x] = root(a[x]); }
	bool same(int x, int y) { return root(x) == root(y); }
	int merge(int x, int y) { a[root(x)] = root(y); }
} dsu;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector< pair<int, int> > vec(2*n);
	for (int i = 0; i < n; ++i) {
		int l, r; cin >> l >> r;
        vec[i<<1] = make_pair(l, 0);
        vec[i<<1|1] = make_pair(r, 1);
	}
    sort(vec.begin(), vec.end());

    long long ans = 0;
    int cnt[2]; cnt[0] = cnt[1] = 0;
    for (pair<int, int> p : vec) {
		if (cnt[p.second ^ 1] == 0) ++cnt[p.second];
		else --cnt[p.second ^ 1], ans += p.first;
    }
    cout << ans + n;
}