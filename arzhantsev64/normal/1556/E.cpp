#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 7;

template <typename T>
struct seg_tree_min {

    vector<T> t;

    size_t main_size;

    void build(int v, int L, int R, vector<int> & a) {
        if (L == R - 1)
            t[v] = a[L];
        else {
            int M = (L + R) / 2;
            build(2 * v + 1, L, M, a);
            build(2 * v + 2, M, R, a);
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int v, int L, int R, int i, int x) {
        if (R <= i || L > i)
            return;
        else if (L == R - 1)
            t[v] = x;
        else {
            int M = (L + R) / 2;
            update(2 * v + 1, L, M, i, x);
            update(2 * v + 2, M, R, i, x);
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int i, int x) {
        update(0, 0, main_size, i, x);
    }

    int seg_min(int v, int L, int R, int l, int r) {
        if (R <= l || r <= L)
            return INF;
        else if (l <= L && R <= r)
            return t[v];
        else {
            int M = (L + R) / 2;
            return min(seg_min(2 * v + 1, L, M, l, r), seg_min(2 * v + 2, M, R, l, r));
        }
    }

    int seg_min(int l, int r) {
        return seg_min(0, 0, main_size, l, r);
    }

    seg_tree_min() { }

    seg_tree_min(vector<T> & a) {
        main_size = a.size();
        t.resize(a.size() * 4, INF);
        build(0, 0, a.size(), a);
    }
};

template <typename T>
struct seg_tree_max {

    vector<T> t;

    size_t main_size;

    void build(int v, int L, int R, vector<int> & a) {
        if (L == R - 1)
            t[v] = a[L];
        else {
            int M = (L + R) / 2;
            build(2 * v + 1, L, M, a);
            build(2 * v + 2, M, R, a);
            t[v] = max(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int v, int L, int R, int i, int x) {
        if (R <= i || L > i)
            return;
        else if (L == R - 1)
            t[v] = x;
        else {
            int M = (L + R) / 2;
            update(2 * v + 1, L, M, i, x);
            update(2 * v + 2, M, R, i, x);
            t[v] = max(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int i, int x) {
        update(0, 0, main_size, i, x);
    }

    int seg_max(int v, int L, int R, int l, int r) {
        if (R <= l || r <= L)
            return -INF;
        else if (l <= L && R <= r)
            return t[v];
        else {
            int M = (L + R) / 2;
            return max(seg_max(2 * v + 1, L, M, l, r), seg_max(2 * v + 2, M, R, l, r));
        }
    }

    int seg_max(int l, int r) {
        return seg_max(0, 0, main_size, l, r);
    }

    seg_tree_max() { }

    seg_tree_max(vector<T> & a) {
        main_size = a.size();
        t.resize(a.size() * 4, -INF);
        build(0, 0, a.size(), a);
    }
};


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = (i == 0 ? 0 : v[i - 1]) + a[i] - b[i];
    }
    seg_tree_max<int> v_max(v);
    seg_tree_min<int> v_min(v);

	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
        l--;
        int base = (l == 0 ? 0 : v[l - 1]);
        int end  = (r == 0 ? 0 : v[r - 1]);
        int maxx = v_max.seg_max(l, r);
        int minn = v_min.seg_min(l, r);
        // cout << base << ' ' << maxx << ' ' << minn << endl;
        if (end != base || maxx - base > 0)
            cout << -1 << "\n";
        else
            cout << base - minn << "\n";
	}

	return 0;
}

/*
8 5
0 1 2 9 3 2 7 5
2 2 1 9 4 1 5 8

-2 -1 1 0 -1 1 2 -3

*/