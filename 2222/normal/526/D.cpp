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

int n, k;
char s[1000111];
int p[1000111];

bool good(int n, int k) {
    if (n < k)
        return false;
    n /= (n / k);
    return n == k;
}

int main() {
	scanf("%d%d%s", &n, &k, s);
    assert(strlen(s) == n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        for (; j > 0 && s[i] != s[j]; j = p[j - 1]);
        if (s[i] == s[j])
            ++j;
        p[i] = j;
    }
    REP (i, n) {
        int c = i - p[i] + 1;
        int j0 = (i + 1) / c;
        int j1 = i / c + 1;
        if (j0 > 0 && good(j0, k) || j1 > 1 && good(j1 - 1, k))
            putchar('1');
        else
            putchar('0');
    }
    puts("");
	return 0;
}