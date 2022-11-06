#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 1

const int M = 3e7;
const int A = 111111;
//const int M = 500;
//const int A = 111;
int ch[M][2];
int mn[M];
int nsz = 1;

int rs[A];

void add(int n, int x, int i) {
    if (i < 0) {
        return;
    }
    int w = hbit(x, i);
    if (ch[n][w] == 0) {
        ch[n][w] = nsz++;
    }
    add(ch[n][w], x, i - 1);
    mn[n] = 1e9;
    if (ch[n][0]) {
        mn[n] = min(mn[n], mn[ch[n][0]]);
    }
    if (ch[n][1]) {
        mn[n] = min(mn[n], mn[ch[n][1]] | shl(i));
    }
}

int get(int n, int x, int s) {
    int cur = 0;
    repr(i, 17, 0) {
        int wt = 1 - hbit(x, i);
        int w = wt;
        if (ch[n][1] == 0 || (cur | shl(i) | mn[ch[n][1]]) > s) {
            w = 0;
        } else {
            if (!ch[n][wt]) {
                w = 1 - wt;
            }
        }
        if (!ch[n][w]) {
            return -1;
        }
        n = ch[n][w];
        if (w) {
            cur |= shl(i);
        }
    }
    return cur;
}

void solve(istream& cin, ostream& cout) {
    nsz = 1;
    memset(rs, 0, sizeof(rs));
    memset(ch, 0, sizeof(int) * M * 2);
    memset(mn, 0, sizeof(mn));

    vector<int> ds[A];
    rep(i, 1, A) {
        for (int j = i; j < A; j += i) {
            ds[j].push_back(i);
        }
    }

    int q;
    cin >> q;
    rep(iq, 0, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            for (int d : ds[x]) {
                if (rs[d] == 0) {
                    rs[d] = nsz++;
                }
                add(rs[d], x, 16);
            }
        } else {
            int x, k, s;
            cin >> x >> k >> s;
            if (x % k != 0 || rs[k] == 0) {
                cout << "-1\n";
                continue;
            }
            int a = get(rs[k], x, s - x);
            cout << a << "\n";
        }
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand(125121);
    for (int ti = 0; ti < 100000; ti++) {
        cerr << ti << endl;
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//mlqwlq