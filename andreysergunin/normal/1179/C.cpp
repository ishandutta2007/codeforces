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
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);
   
const int MAXM = 1000300;

class Tree {
public:
    Tree() {}

    Tree(int nn) {
        n = nn;
        mn.resize(4 * n);
        sum.resize(4 * n);
    }

    void update(int pos, int val) {
        update(0, 0, n, pos, val);
    }

    int get_pos() {
        if (mn[0] >= 0) {
            return -1;
        }
        return get_pos(0, 0, n);
    }

    int get(int pos) {
        return get(0, 0, n, pos);
    }
   
private:
    void update(int v, int l, int r, int pos, int val) {
        if (l + 1 == r) {
            mn[v] += val;
            sum[v] += val;
            return;
        }
        int m = (l + r) / 2;
        if (pos < m) {
            update(2 * v + 1, l, m, pos, val);
        } else {
            update(2 * v + 2, m, r, pos, val);
        }
        mn[v] = min(mn[2 * v + 2], sum[2 * v + 2] + mn[2 * v + 1]);
        sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
    }

    int get_pos(int v, int l, int r, int cur = 0) {
        if (l + 1 == r) {
            return l;
        }
        int m = (l + r) / 2;
        if (cur + mn[2 * v + 2] <= -1) {
            return get_pos(2 * v + 2, m, r, cur);
        } 
        return get_pos(2 * v + 1, l, m, cur + sum[2 * v + 2]);
    }

    int get(int v, int l, int r, int pos) {
        if (l + 1 == r) {
            return sum[v];
        }
        int m = (l + r) / 2;
        if (pos < m) {
            return get(2 * v + 1, l, m, pos) + sum[2 * v + 2];
        } 
        return get(2 * v + 2, m, r, pos);
    }

    int n;
    vector<int> mn;
    vector<int> sum;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  


    int n, m;
    cin >> n >> m;

    Tree tree(MAXM);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tree.update(a[i], -1);
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        tree.update(b[i], 1);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            tree.update(a[pos], 1);
            a[pos] = val;
            tree.update(a[pos], -1);
        } else {
            int pos, val;
            cin >> pos >> val;
            --pos;
            tree.update(b[pos], -1);
            b[pos] = val;
            tree.update(b[pos], 1);
        }

        cout << tree.get_pos() << endl;
    }
}