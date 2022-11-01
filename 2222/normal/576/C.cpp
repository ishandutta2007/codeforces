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

vector<int> a[1000][1000];

int main() {
    int n;
    scanf("%d", &n);
    REP (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[min(x / 1000, 999)][min(y / 1000, 999)].pb(i);
    }
    srand(42 ^ 13);
    REP (i, 1000) {
        vector<int> p;
        REP (j, 1000) {
            random_shuffle(all(a[i][j]));
            for (int x : a[i][j])
                p.pb(x);
        }
        if (i % 2) reverse(all(p));
        for (int x : p) printf("%d ", x + 1);
    }
    puts("");
    return 0;
}