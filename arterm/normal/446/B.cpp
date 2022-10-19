#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define M 1010
#define N 1000100
#define INF 1000000000100000000ll
#define long long long

long n, m, r[M], c[M], k, p, sr[N], sc[N];
priority_queue<long> q;

void read() {
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; ++i)
        for (int j = 0, x; j < m; ++j) {
            cin >> x;
            r[i] += x;
            c[j] += x;
        }
}

void get(int n, long dec, long * a, long * ans) {
    while (!q.empty())
        q.pop();
    ans[0] = 0;
    for (int i = 0; i < n; ++i)
        q.push(a[i]);
    for (int i = 1; i <= k; ++i) {
        long x = q.top();
        q.pop();
        ans[i] = ans[i - 1] + x;
        x -= dec;
        q.push(x);
    }
}

void kill() {
    long ans = -INF;
    get(n, p * m, r, sr);
    get(m, p * n, c, sc);
    for (int i = 0; i <= k; ++i)
        ans = max(ans, sr[i] + sc[k - i] - p * i * (k - i));
    cout << ans << "\n";
}



int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();

    return 0;
}