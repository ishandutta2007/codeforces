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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> prev(n);
    vector<int> next(n);
    REP (i, n) {
        scanf("%d", &a[i]);
        int j = i - 1;
        for (; j >= 0 && a[j] >= a[i]; j = prev[j]);
        prev[i] = j;
    }
    vector<int> s(n + 1);
    for (int i = n; i --> 0; ) {
        int j = i + 1;
        for (; j < n && a[j] >= a[i]; j = next[j]);
        next[i] = j;
        int k = j - prev[i] - 1;
        assert(0 < k && k <= n);
        s[k] = max(s[k], a[i]);
    }
    for (int i = n; i --> 0; ) {
        s[i] = max(s[i], s[i + 1]);
    }
    REP (i, n) {
        if (i) putchar(' ');
        printf("%d", s[i + 1]);
    }
    puts("");
    return 0;
}