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
    int n;
    cin >> n;
    ++n;
    vc<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vc<int> a1, a2;
    a1.push_back(0);
    a2.push_back(0);
    bool ok = false;
    rep(i, 1, n) {
        if (a[i] > 1 && a[i - 1] > 1) {
            ok = true;
            {
                int p1 = a1.size();
                rep(j, 0, a[i]) {
                    a1.push_back(p1);
                }
            }
            {
                int p1 = a2.size();
                int p2 = a2.size() - 1;
                a2.push_back(p2);
                rep(j, 1, a[i]) {
                    a2.push_back(p1);
                }
            }
        } else {
            {
                int p1 = a1.size();
                rep(j, 0, a[i]) {
                    a1.push_back(p1);
                }
            }
            {
                int p1 = a2.size();
                rep(j, 0, a[i]) {
                    a2.push_back(p1);
                }
            }
        }
    }

    if (!ok) {
        cout << "perfect";
    } else {
        cout << "ambiguous\n";
        for (int i : a1) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i : a2) {
            cout << i << " ";
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