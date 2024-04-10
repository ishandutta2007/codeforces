#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 305, Gm = 3505, Inf = 0x3f3f3f3f;
const int S = 0, D = Gm - 1;

pair<int, int> A[Nmax];
int Dp[2][1 << 20];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return __gcd(a, b);
}

vector<int> getDivs(int x) {
    vector<int> ret;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            ret.push_back(i);
        }
    }
    if (x > 1) {
        ret.push_back(x);
    }
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> A[i].first;
    for (int i = 1; i <= N; ++i)
        cin >> A[i].second;

    int g = 0;
    for (int i = 1; i <= N; ++i)
        g = gcd(g, A[i].first);

    if (g > 1) {
        cout << "-1\n";
        return 0;
    }

    int ans = Inf;
    for (int i = 1; i <= N; ++i) {
        vector<int> divs = getDivs(A[i].first);
        int M = divs.size();
        memset(Dp[0], Inf, sizeof(int) * (1 << M));
        Dp[0][0] = 0;
        for (int j = 1, u = 1; j <= N; ++j, u ^= 1) {
            memcpy(Dp[u], Dp[u ^ 1], sizeof(int) * (1 << M));
            int mask = 0;
            for (int k = 0; k < M; ++k)
                if (A[j].first % divs[k] != 0)
                    mask |= 1 << k;
            for (int conf = 0; conf < 1 << M; ++conf)
                Dp[u][conf | mask] = min(Dp[u][conf | mask], Dp[u ^ 1][conf] + A[j].second);
        }
        ans = min(ans, Dp[N & 1][(1 << M) - 1] + A[i].second);
    }

    cout << ans << '\n';
}