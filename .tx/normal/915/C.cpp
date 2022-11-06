#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    string s;
    multiset<int> a;
    cin >> s;
    for (char c : s) {
        a.insert(c - '0');
    }
    cin >> s;
    if (s.size() > a.size()) {
        for (auto it = a.rbegin(); it != a.rend(); ++it) {
            cout << *it;
        }
        return;
    }

    multiset<int> b;
    for (char c : s) {
        b.insert(c -'0');
    }
    if (a == b) {
        cout << s;
        return;
    }

    lint ans = 0;
    vector<int> ia(a.begin(), a.end());
    if (ia[0] == 0) {
        rep(i, 1, a.size()) {
            if (ia[i]) {
                swap(ia[0], ia[i]);
                break;
            }
        }
    }
    for (int i : ia) {
        ans = ans * 10 + i;
    }

    rep(i, 0, s.size()) {
        int c = s[i] - '0';

        int p = -1;
        rep(j, i == 0 ? 1 : 0, c) {
            if (a.find(j) != a.end()) {
                p = j;
            }
        }
        if (p != -1) {
            lint cur = 0;
            rep(t, 0, i) {
                cur = cur * 10 + s[t] - '0';
            }
            cur = cur * 10 + p;
            bool wp = false;
            for (auto it = a.rbegin(); it != a.rend(); ++it) {
                if (*it == p) {
                    if (wp) {
                        cur = cur * 10 + *it;
                    }
                    wp = true;
                } else {
                    cur = cur * 10 + *it;
                }
            }
            ans = max(ans, cur);
        }

        if (a.find(c) == a.end()) {
            break;
        }
        a.erase(a.find(c));
    }

    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
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
}