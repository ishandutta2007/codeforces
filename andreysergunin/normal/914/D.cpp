#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 5005000;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

class SegmentTree {
public:

    SegmentTree(const vector<int> &a) {
        n = sz(a);
        g.resize(4 * n);
        build(0, 0, n, a);
    }

    void update(int pos, int val) {
        update(0, 0, n, pos, val);
    }

    int get(int pos, int d) {
        return get(0, 0, n, pos, d);
    }

private:

    void build(int v, int l, int r, const vector<int> &a) {
        if (r - l == 1) {
            g[v] = a[l];
        } else {
            int mid = (l + r) / 2;
            build(2 * v + 1, l, mid, a);
            build(2 * v + 2, mid, r, a);
            g[v] = gcd(g[2 * v + 1], g[2 * v + 2]);
        }
    }

    void update(int v, int l, int r, int pos, int val) {
        if (r - l == 1) {
            g[v] = val;
            return ;
        }
        int mid = (l + r) / 2;
        if (pos < mid) {
            update(2 * v + 1, l, mid, pos, val);
        } else {
            update(2 * v + 2, mid, r, pos, val);
        }
        g[v] = gcd(g[2 * v + 1], g[2 * v + 2]);
    }


    int get(int v, int l, int r, int pos, int d) {
        if (r - l == 1) {
            return (g[v] % d == 0 ? r : l);
        }
        int mid = (l + r) / 2;
        if (pos < mid) {
            int res = get(2 * v + 1, l, mid, pos, d);
            if (res < mid) {
                return res;
            }
        }
        if (g[2 * v + 2] % d == 0) {
            return r;
        }
        return get(2 * v + 2, mid, r, pos, d);
    }

    int n;
    vector<int> g;
};

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree tree(a);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, d;
            cin >> l >> r >> d;

            --l;
            int pos = tree.get(l, d);
            if (pos >= r - 1) {
                cout << "YES\n";
                continue;
            }
            ++pos;
            pos = tree.get(pos, d);
            if (pos >= r) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

        } else {
            int pos, val;
            cin >> pos >> val;
            --pos;
            tree.update(pos, val);
        }
    }



    return 0;
}