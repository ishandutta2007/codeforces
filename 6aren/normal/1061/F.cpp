#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // or mt19937 for int
long long Rand(long long l, long long r) {
    if (r < l) return 0;
    return l + rng() % (r - l + 1);
}

int n, k, h;

bool query(int x, int y, int z) {
    cout << "? " << x << ' ' << y << ' ' << z << endl;
    string s;
    cin >> s;
    if (s == "Yes") return true;
    else return false;
}

bool isLeaf(int x) {
    int u  = Rand(1, n);
    while (u == x) u = Rand(1, n);
    for (int i = 1; i <= n; i++) {
        if (i == u || i == x) continue;
        if (query(u, x, i)) return false;
    }
    return true;
}

int l1 = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    srand(time(NULL));
    cin >> n >> k;
    int cur = 1;
    int nNodes = 1;
    while (nNodes < n) {
        cur *= k;
        nNodes += cur;
        h++;
    }
    while (true) {
        l1 = Rand(1, n);
        if (isLeaf(l1)) break;
    }
    int l2 = 0;
    while (true) {
        l2 = Rand(1, n);
        while (l2 == l1) l2 = Rand(1, n);
        if (!isLeaf(l2)) continue;
        vector<int> candidate_roots;
        for (int i = 1; i <= n; i++) {
            if (i == l1 || i == l2) continue;
            if (query(l1, i, l2)) candidate_roots.pb(i);
        }
        if (candidate_roots.size() != 2 * h - 1) continue;
        sort(all(candidate_roots), [](int x, int y) {
            return query(l1, x, y);
        });
        cout << "! " << candidate_roots[h - 1] << endl;
        return 0;
    }

    return 0;
}