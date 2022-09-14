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
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const ll INF = 1e18;

struct SegmentTree {
    SegmentTree() {}

    SegmentTree(int n) : n(n) {
        a.resize(4 * n);
        pr.resize(4 * n);
        pos.resize(4 * n);
        build(0, 0, n);
    }

    void build(int v, int lf, int rg) {
        if (rg - lf == 1) {
            pos[v] = lf;
            return;
        }
        int mid = (lf + rg) / 2;
        build(2 * v + 1, lf, mid);
        build(2 * v + 2, mid, rg);
        pos[v] = pos[2 * v + 2];
    }

    void add(int l, int r, ll val) {
        add(0, 0, n, l, r, val);
    }

    void add(int v, int lf, int rg, int l, int r, ll val) {
        if (rg <= l || r <= lf) {
            return;
        }
        if (l <= lf && rg <= r) {
            pr[v] += val;
            return;
        }
        push(v);
        int mid = (lf + rg) / 2;
        add(2 * v + 1, lf, mid, l, r, val);
        add(2 * v + 2, mid, rg, l, r, val);
        relax(v);
    }

    int get() {
        return pos[0];
    }

    void relax(int v) {
        ll x = a[2 * v + 1] + pr[2 * v + 1];
        ll y = a[2 * v + 2] + pr[2 * v + 2];
        if (x < y) {
            pos[v] = pos[2 * v + 1];
            a[v] = x;
        } else {
            pos[v] = pos[2 * v + 2];
            a[v] = y;
        }
    }

    void push(int v) {
        pr[2 * v + 1] += pr[v];
        pr[2 * v + 2] += pr[v];
        a[v] += pr[v];
        pr[v] = 0;
    }

    int n;
    vector<ll> a, pr, pos;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif
    
    int n;
    cin >> n;

    vector<ll> a(n);

    SegmentTree tree(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tree.add(i, i + 1, a[i]);
    }

    vector<int> res(n);
    
    for (int i = 1; i <= n; ++i) {
        int pos = tree.get();    
        res[pos] = i;
        tree.add(pos, pos + 1, INF);
        tree.add(pos, n, -i);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
 
}