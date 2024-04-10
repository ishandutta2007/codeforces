#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const i64 Inf = 1LL << 62;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    i64 N;
    cin >> N;

    i64 ans1 = 1LL << 62, ans2 = -(1LL << 62);

    vector<int> divs;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            divs.push_back(i);
            if (i * i < N) divs.push_back(N / i);
        }
    }
    sort(divs.begin(), divs.end());
    int M = divs.size();
    vector<i64> max1(M, -Inf), max2(M, -Inf), min1(M, Inf), min2(M, Inf);
    for (int i = 0; i < M; ++i) {
        int x = divs[i];
        for (int j = 0; j <= i; ++j) {
            int y = divs[j];
            if (x % y != 0) continue;

            max1[i] = max(max1[i], 1LL * (y + 2) * (x / y + 2));
            max2[i] = max(max2[i], 1LL * (y + 1) * (x / y + 2));
            min1[i] = min(min1[i], 1LL * (y + 2) * (x / y + 2));
            min2[i] = min(min2[i], 1LL * (y + 1) * (x / y + 2));
        }
    }
    for (int i = 0; i < M; ++i) {
        int x = divs[i], y = N / x;
        ans1 = min(ans1, 1LL * (y + 1) * min1[i]);
        ans1 = min(ans1, 1LL * (y + 2) * min2[i]);
        ans2 = max(ans2, 1LL * (y + 1) * max1[i]);
        ans2 = max(ans2, 1LL * (y + 2) * max2[i]);
    }
    ans1 -= N;
    ans2 -= N;

    cout << ans1 << ' ' << ans2 << '\n';
}