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

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    map<string, vector<string>> m;
    rep(i, 0, n) {
        string s;
        int x;
        cin >> s >> x;
        rep(j, 0, x) {
            string y;
            cin >> y;
            m[s].push_back(y);
        }
    }

    cout << m.size() << "\n";

    for (auto& p : m) {
        sort(p.second.begin(), p.second.end(), [](string& a, string& b){ return a.size() < b.size();});
        vector<string> ans;
        rep(i, 0, p.second.size()) {
            string& s = p.second[i];
            bool ok = true;
            rep(j, i + 1, p.second.size()) {
                string& t = p.second[j];
                if (t.substr(t.size() - s.size(), s.size()) == s) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.push_back(s);
            }
        }
        cout << p.first << " " << ans.size();
        for (string& s : ans) {
            cout << " " << s;
        }
        cout << "\n";
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