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

int ff(int x, int k) {
    if (k == 0)
        return x < 3 ? x : (x + 1) % 2;
    if (x < 5)
        return (const int[]){0, 1, 0, 1, 2}[x];
    if (x % 2)
        return 0;
    int r = ff(x / 2, k);
    return r ? (r ^ 3) : 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    k %= 2;
    int res = 0;
    REP (i, n) {
        int x;
        cin >> x;
        res ^= ff(x, k);
    }
    cout << (res ? "Kevin" : "Nicky") << endl;    
    return 0;
}