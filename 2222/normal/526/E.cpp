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

int n, q;
int a[2000222];
pii f[2000222];

int main() {
	scanf("%d%d", &n, &q);
    REP (i, n) {
        scanf("%d", a + i);
        a[i + n] = a[i];
    }
    f[0].Y = -1;
    for (; q > 0; -- q) {
        long b, w = 0;
        cin >> b;
        int j = 0;
        int res = n;
        REP (i, 2 * n) {
            w += a[i];
            for (; w > b; w -= a[j++]);
            assert(w <= b);
            f[i].X = j ? f[j - 1].X + 1 : 0;
            f[i].Y = j ? ~f[j - 1].Y ? f[j - 1].Y : j - 1 : -1;
            if (i - f[i].Y >= n)
                res = min(res, f[i].X);
        }
        cout << max(res, 1) << endl;
    }
	return 0;
}