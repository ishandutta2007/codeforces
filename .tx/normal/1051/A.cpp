#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

bool isGood(string s) {
    bool ff = false, fF = false, f1 = false;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            ff = true;
        } else if (c >= 'A' && c <= 'Z') {
            fF = true;
        } else if (c >= '0' && c <= '9') {
            f1 = true;
        }
    }
    return ff && fF && f1;
}

string get(string s) {
    if (isGood(s)) {
        return s;
    }

    string tc = "aA1";

    int n = s.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            char oc = s[i];
            s[i] = tc[j];
            if (isGood(s)) {
                return s;
            }
            s[i] = oc;
        }
    }

    for (int i = 0; i < n; i++) {
        char oi = s[i];
        for (int j = i + 1; j < n; j++) {
            char oj = s[j];
            for (int t1 = 0; t1 < 3; t1++) {
                for (int t2 = t1 + 1; t2 < 3; t2++) {
                    s[i] = tc[t1];
                    s[j] = tc[t2];
                    if (isGood(s)) {
                        return s;
                    }
                }
            }
            s[j] = oj;
        }
        s[i] = oi;
    }

    return tc + s.substr(3, n - 3);
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        string s;
        cin >> s;
        cout << get(s) << "\n";
    }

    return 0;
}//cipogb