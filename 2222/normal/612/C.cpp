#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int f[128];

int main() {
    f['('] = 1;
    f['<'] = 2;
    f['{'] = 3;
    f['['] = 4;
    f[')'] = -1;
    f['>'] = -2;
    f['}'] = -3;
    f[']'] = -4;
    ios::sync_with_stdio(false);
    string s;
    for (; getline(cin, s); ) {
        int res = 0;
        vector<int> u;
        for (char c : s) {
            int x = f[c];
            if (x > 0) {
                u.pb(x);
            } else {
                if (sz(u) == 0) {
                    res = -1;
                    break;
                }
                res += (u.back() + x != 0);
                u.pop_back();
            }
        }
        if (sz(u)) res = -1;
        if (res < 0) {
            cout << "Impossible" << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}