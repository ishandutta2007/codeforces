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

typedef vector<int> vi;
typedef pair<int, int> pii;

char s[111];

int main() {
	int n;
    scanf("%d\n%s", &n, s);
    assert(strlen(s) == n);
    REP (j, n) REP (i, j) {
        bool ok = true;
        REP (k, 5) {
            int x = i + (j - i) * k;
            ok &= x < n && s[x] == '*';
        }
        if (ok) {
            puts("yes");
            return 0;
        }
    }
    puts("no");
	return 0;
}