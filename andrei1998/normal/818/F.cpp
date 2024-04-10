#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

lint test(int N) {
    if (N <= 5)
        return N - 1;

    int st = 1;
    int dr = N - 3;
    int ans = N - 2;

    while (st <= dr) {
        int x = st + (dr - st) / 2;
        if (2LL * x > (N - x) * (N - x - 1LL)) {
            ans = x;
            dr = x - 1;
        }
        else
            st = x + 1;
    }

    return max(2LL * (ans - 1), ans + (N - ans) * (N - ans - 1LL) / 2);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int Q = 0;
    cin >> Q;
    while (Q --) {
        int N;
        cin >> N;
        cout << test(N) << '\n';
    }
    return 0;
}