#include <algorithm>
#include <iostream>
#include <cassert>
#include <bitset>
#include <random>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    string s;
    cin >> m >> s;
    int n = sz(s);
    vector<bool> u(n);
    int maxC = 0;
    REP (c, 26) {
        int prev = -1;
        REP (i, n) {
            if (s[i] - 'a' == c) u[i] = true;
            if (u[i] && i - prev <= m) prev = i;
        }
        if (n - prev <= m) { maxC = c; break; }
    }
    REP (i, n) if (s[i] - 'a' == maxC) u[i] = false;
    vector<int> f(n);
    deque<int> q;
    int prev = -1;
    u.pb(true);
    REP (i, n + 1) {
        if (u[i]) {
            for (; i - prev > m; ) {
                assert(!q.empty());
                int j = q.front();
                q.pop_front();
                if (!q.size() || q.front() - prev > m) {
                    u[j] = true;
                    prev = j;
                }
            }
            prev = i;
            q.clear();
        } else if (s[i] - 'a' == maxC) {
            q.pb(i);
        }
    }
    string res;
    REP (i, n) if (u[i]) res += s[i];
    sort(all(res));
    cout << res << endl;
    return 0;
}