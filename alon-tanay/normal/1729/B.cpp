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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string num;
        cin >> num;
        vector<char> res;
        int idx = n;
        while (idx > 0) {
            idx--;
            // cout << idx << endl;
            int x;
            if (num[idx] == '0') {
                idx--;
                x = num[idx] - '0';
                x += (num[--idx] - '0') * 10;
            } else {
                x = num[idx] - '0';
            }
            // cout << x << "\n";
            res.push_back('a' + (x - 1));
        }
        reverse(res.begin(), res.end());
        for (char c : res) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}