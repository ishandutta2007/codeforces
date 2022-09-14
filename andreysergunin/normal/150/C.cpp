#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const double EPS = 1e-9;

class SegmentTree {
private:
    struct Node {
        double pref;
        double suff;
        double sum;
        double ans;
    };

public: 
    SegmentTree() {};
    SegmentTree(int n) : n(n) {
        nd.resize(4 * n);
    };

    SegmentTree(const vector<double> &arr) {
        n = sz(arr);
        nd.resize(4 * n);
        buildTree(0, 0, n, arr);
    }

    double get(int l, int r) {
        return get(0, 0, n, l, r).ans;
    }


private:
    void buildTree(int v, int l, int r, const vector<double> &arr) {
        if (r - l == 1) {
            if (arr[l] > -EPS) {
                nd[v] = {arr[l], arr[l], arr[l], arr[l]};
            } else {
                nd[v] = {0., 0., arr[l], 0.};
            }
        } else {
            int mid = (l + r) / 2;
            buildTree(2 * v + 1, l, mid, arr);
            buildTree(2 * v + 2, mid, r, arr);
            nd[v] = merge(nd[2 * v + 1], nd[2 * v + 2]);
        }
    }

    Node merge(const Node &u, const Node &w) {
        Node res = {u.pref, w.suff, u.sum + w.sum, 0.};
        res.pref = max(res.pref, u.sum + w.pref);
        res.suff = max(res.suff, u.suff + w.sum);
        res.ans = max({u.ans, w.ans, u.suff + w.pref});
        return res;
    }

    Node get(int v, int lf, int rg, int l, int r) {
        // cout << lf << " " << rg << " " << l  << " " << r << endl;

        if (r <= lf || rg <= l)
            return {0., 0., 0., 0.};

        if (l <= lf && rg <= r)
            return nd[v];

        int mid = (lf + rg) / 2;
        Node u = get(2 * v + 1, lf, mid, l, r);
        Node w = get(2 * v + 2, mid, rg, l, r);
        return merge(u, w); 
    }

    int n;
    vector<Node> nd;
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, c;
    cin >> n >> m >> c;
    vector<double> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    vector<double> p(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> p[i];
        p[i] /= 100;
    }   

    vector<double> arr(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        arr[i] = (x[i + 1] - x[i]) / 2 - c * p[i];
    }

    SegmentTree tree(arr);

    double ans = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        // cout << "!" << l << " " << r << endl;
        --l; --r;
        ans += tree.get(l, r);
    }

    cout.precision(12);
    cout << fixed;
    cout << ans << endl;

    return 0;
}