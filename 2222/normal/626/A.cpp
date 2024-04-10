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

int main() {
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    REP (i, n) {
        int x = 0, y = 0;
        FOR (j, i, n) {
            switch (s[j]) {
                case 'U': y -= 1; break;
                case 'R': x += 1; break;
                case 'D': y += 1; break;
                case 'L': x -= 1; break;
            }
            if (x == 0 && y == 0) ++res;
        }
    }
    cout << res << endl;
    return 0;
}