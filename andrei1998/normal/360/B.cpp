#include <iostream>
#include <cstdlib>

using namespace std;

const int NMAX = 2000 + 5;

int N, K;
int v[NMAX];

int dp[NMAX];

bool works(int L) {
    for (int i = 1; i <= N; ++ i) {
        dp[i] = i - 1;
        for (int j = 1; j < i; ++ j) {
            int dy = abs(v[i] - v[j]);
            int dx = i - j;

            if (dy <= 1ll * L * dx)
                dp[i] = min(dp[i], dp[j] + i - j - 1);
        }

        if (dp[i] + N - i <= K)
            return true;
    }

    return false;
}

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    if (K == N) {
        cout << "0\n";
        return 0;
    }

    int st = 0;
    int dr = 2000000000 + 5;
    int ans = dr + 1;

    while (st <= dr) {
        int mid = st + (dr - st) / 2;
        if (works(mid)) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}