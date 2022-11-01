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

int n;
int a[2222];
int f[2222];

int main() {
	cin >> n;
    int m = (1 << (n + 1)) - 1;
    FOR (i, 2, m + 1)
        cin >> a[i];
    int res = 0;
    for (int i = m / 2; i > 0; --i) {
        int l = f[i * 2] + a[2 * i];
        int r = f[i * 2 + 1] + a[2  * i + 1];
        f[i] = max(l, r);
        res += abs(l - r);
    }
    cout << res << endl;
	return 0;
}