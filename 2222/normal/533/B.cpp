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

int n;
vector<int> childs[200500];
int a[200500];

pair<long, long> dfs(int x) {
    long sum = 0, worst = -1ull/2;
    int parity = 0;
    for (int y : childs[x]) {
        auto z = dfs(y);
        if (z.X > z.Y) {
            sum += z.X;
            parity ^= 1;
            worst = min(worst, z.X - z.Y);
        } else {
            sum += z.Y;
            worst = min(worst, z.Y - z.X);
        }
    }
    long odd = sum + a[x] - parity * worst;
    long even = sum - parity * worst;
    if (parity)
        odd = max(odd, sum);
    return {odd, even};
}

int main() {
    scanf("%d", &n);
    REP (i, n) {
        int p;
        scanf("%d%d", &p, a + i);
        if (--p >= 0)
            childs[p].push_back(i);
    }
    auto res = dfs(0);
    cout << max(res.X, res.Y) << endl;
    return 0;
}