#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int cnta = a + c + d;
        int cntb = b + c + d;
        for (char cc : s) {
            if (cc == 'A') --cnta;
            else --cntb;
        }
        if (cnta != 0 || cntb != 0) {
            cout << "NO\n";
            continue;
        }
        multiset <int> aa, ba2, ab, bb, ba3;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (i != n - 1 && s[i] != s[i + 1]) {
                int si = i;
                char st = s[i];
                while (i < n - 1 && s[i] != s[i + 1]) {
                    ++i;
                }
                int len = i - si + 1;
                if (st == 'A' && s[i] == 'A') aa.insert(len);
                if (st == 'A' && s[i] == 'B') ab.insert(len);
                if (st == 'B' && s[i] == 'A') {
                    if (len == 2) ba2.insert(len);
                    else ba3.insert(len);
                }
                if (st == 'B' && s[i] == 'B') bb.insert(len);
            }
        }
        while (c > 0) {
            if (!ab.empty()) {
                c--;
                int x = *ab.begin();
                ab.erase(ab.begin());
                x -= 2;
                if (x > 0) ab.insert(x);
                continue;
            }
            if (!bb.empty()) {
                c--;
                int x = *bb.begin();
                x -= 2;
                bb.erase(bb.begin());
                if (x > 1) bb.insert(x);
                continue;
            }
            if (!aa.empty()) {
                c--;
                int x = *aa.begin();
                x -= 2;
                aa.erase(aa.begin());
                if (x > 1) aa.insert(x);
                continue;
            }
            if (!ba3.empty()) {
                c--;
                int ln = *ba3.rbegin();
                ba3.erase(ba3.find(ln));
                ln -= 3;
                if (ln > 1) bb.insert(ln);
                continue;
            }
            break;
        }
        if (c == 0) {
            for (int i : aa) {
                d -= i / 2;
            }
            for (int i : ba2) {
                d--;
            }
            for (int i : ba3) {
                d -= i / 2;
            }
            for (int i : ab) {
                d -= (i - 1) / 2;
            }
            for (int i : bb) {
                d -= i / 2;
            }
            if (d <= 0) cout << "YES\n";
            else cout << "NO\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}