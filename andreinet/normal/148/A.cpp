#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005;
bool A[Nmax];

void mark(int k, int N) {
    for (int i = k; i <= N; i += k)
        A[i] = true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    mark(k, d);
    mark(l, d);
    mark(m, d);
    mark(n, d);

    int ans = 0;
    for (int i = 1; i <= d; ++i)
        ans += A[i];

    cout << ans << '\n';
}