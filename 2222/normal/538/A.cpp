#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int main() {
    string want = "CODEFORCES";
    string s;
    getline(cin, s);
    if (sz(s) < sz(want)) {
        puts("NO");
        return 0;
    }
    int prefix = 0;
    int suffix = 0;
    for (; prefix < sz(want) && want[prefix] == s[prefix]; ++prefix);
    for (; suffix < sz(want) && want[sz(want) - 1 - suffix] == s[sz(s) - 1 - suffix]; ++suffix);
    puts(prefix + suffix >= sz(want) ? "YES" : "NO");
    return 0;
}