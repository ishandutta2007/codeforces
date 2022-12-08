#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> opt(n);
    for (int i = 0; i < n; i++) {
        opt[i] = i + 1;
    }
    while (true) {
        // cout << "~ ";
        // for (int o : opt) {
        //     cout << o << " ";
        // }
        // cout << endl;
        int sz = opt.size();
        if (sz == 2) {
            cout << "! " << opt[0] << endl;
            string rep;
            cin >> rep;
            if (rep[1] == ')') {
                return 0;
            }
            cout << "! " << opt[1] << endl;
            cin >> rep;
            return 0;
        } else if (sz == 1) {
            cout << "! " << opt[0] << endl;
            string rep;
            cin >> rep;
            return 0;
        } else if (sz == 3) {
            cout << "? 1 " << opt[0] << endl;
            string rep1;
            cin >> rep1;
            cout << "? 1 " << opt[0] << endl;
            string rep2;
            cin >> rep2;
            if (rep1 == rep2) {
                if (rep1[0] == 'Y') {
                    opt = {opt[0]};
                } else {
                    opt = {opt[1], opt[2]};
                }
            } else {
                if (rep2[0] == 'Y') {
                    cout << "? 1 " << opt[1] << endl;
                    string rep3;
                    cin >> rep3;
                    opt = {opt[0], (rep3[0] == 'Y') ? opt[1] : opt[2]};
                    continue;
                }
                cout << "? 1 " << opt[0] << endl;
                cin >> rep1;
                if (rep1[0] == 'N') {
                    opt = {opt[1], opt[2]};
                    continue;
                }
                cout << "? 1 " << opt[1] << endl;
                string rep3;
                cin >> rep3;
                opt = {opt[0], (rep3[0] == 'Y') ? opt[1] : opt[2]};
            }
            continue;
        }
        int h = sz / 2;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < h; i++) {
            a.push_back(opt[i]);
        }
        for (int i = h; i < sz; i++) {
            b.push_back(opt[i]);
        }
        cout << "? " << a.size();
        for (int ai : a) {
            cout << " " << ai;
        }
        cout << endl;
        string rep;
        cin >> rep;
        if (rep[0] == 'N') {
            swap(a, b);
        }
        int hb = b.size() / 2;
        cout << "? " << hb;
        for (int i = 0; i < hb; i++) {
            cout << " " << b[i];
        }
        cout << endl;
        cin >> rep;
        if (rep[0] == 'Y') {
            for (int i = 0; i < hb; i++) {
                a.push_back(b[i]);
            }
        } else {
            for (int i = hb; i < b.size(); i++) {
                a.push_back(b[i]);
            }
        }
        opt = a;
    }
    return 0;
}