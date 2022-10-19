#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

struct Node {
    int mn, sum;
};

int n, q, a[N];
Node it[4 * N];
int lazy[4 * N];

void combine(int k) {
    it[k].mn = min(it[2 * k].mn, it[2 * k + 1].mn);
    it[k].sum = it[2 * k].sum + it[2 * k + 1].sum;
}

void build(int k, int l, int r) {
    if (l == r) {
        it[k].mn = it[k].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    combine(k);
}

void down(int k, int l, int r) {
    int mid = (l + r) / 2;
    int val = lazy[k];
    if (val == 0) {
        return;
    }
    lazy[k] = 0;
    it[2 * k].sum = (mid - l + 1) * val;
    it[2 * k].mn = val;
    it[2 * k + 1].sum = (r - mid) * val;
    it[2 * k + 1].mn = val;
    lazy[2 * k] = val;
    lazy[2 * k + 1] = val;
}

void update(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        it[k].mn = val;
        it[k].sum = (r - l + 1) * val;
        lazy[k] = val;
        return;
    }
    down(k, l, r);
    int mid = (l + r) / 2;
    update(2 * k, l, mid, u, v, val);
    update(2 * k + 1, mid + 1, r, u, v, val);
    combine(k);
}

int getFirstLower(int k, int l, int r, int v) {
    // cout << k << ' ' << l << ' ' << r << endl;
    if (it[k].mn > v) return N;
    if (l == r) return l;
    down(k, l, r);
    int mid = (l + r) / 2;
    if (it[2 * k].mn <= v) return getFirstLower(2 * k, l, mid, v);
    else return getFirstLower(2 * k + 1, mid + 1, r, v);
}

int getSum(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return it[k].sum;
    down(k, l, r);
    int mid = (l + r) / 2;
    return getSum(2 * k, l, mid, u, v) + getSum(2 * k + 1, mid + 1, r, u, v);
}

// get smallest id that sum a[1...id] > val
int getId(int k, int l, int r, int val) {
	if (l == r) {
		return (it[k].sum > val ? l : N);
	}
	down(k, l, r);
	int mid = (l + r) / 2;
	if (it[2 * k].sum > val) return getId(2 * k, l, mid, val);
	else return getId(2 * k + 1, mid + 1, r, val - it[2 * k].sum);
}




int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        // cout << q << endl;
        int t, x, y;
        cin >> t >> x >> y;
        // cout << t << ' ' << x << ' ' << y << '\n';
        if (t == 1) {
            int id = getFirstLower(1, 1, n, y);
            if (id <= x) update(1, 1, n, id, x, y);
        } else {
            int res = 0;
            while (true) {
                if (y == 0) break;
                if (x == n + 1) break;
                x = max(getFirstLower(1, 1, n, y), x);
                if (x == N) break;
                int foo = getSum(1, 1, n, 1, x - 1);
                int id = getId(1, 1, n, foo + y);
                if (id == N) id = n + 1;
                // cout << x << ' ' << id << endl;
                y -= getSum(1, 1, n, x, id - 1);
                res += id - x;
                x = id;
            }
            cout << res << '\n';
        }
    }

    return 0;
}