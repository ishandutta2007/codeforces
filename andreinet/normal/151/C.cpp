#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    i64 N;
    cin >> N;

    int cnt = 0;
    int div1 = -1, div2 = -1;
    for (int i = 2; 1LL * i * i <= N; ++i) {
        while (N % i == 0) {
            ++cnt;
            N /= i;
            if (div1 == -1) div1 = i;
            else if (div2 == -1) div2 = i;
        }
    }
    if (N > 1) ++cnt;

    if (cnt <= 1) {
        cout << "1\n0\n";
    } else if (cnt == 2) {
        cout << "2\n";
    } else {
        cout << "1\n" << 1LL * div1 * div2 << '\n';
    }
}