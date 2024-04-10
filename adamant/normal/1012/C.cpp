#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

typedef double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}
ftype cross(point a, point b) {
    return (conj(a) * b).y();
}

const ftype pi = acos(-1);

const int maxn = 4e5 + 42, maxt = 1e3 + 42, mod = 1e9 + 7, sigma = 26;

int par[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

int uni(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return 0;
    }
    par[a] = b;
    return 1;
}

int dp[5005][2505][2][2];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    } else if(n == 2) {
        cout << (A[0] == A[1]) << endl;
        return 0;
    }
    int k = (n + 1) / 2;
    memset(dp, 0x3F, sizeof(dp));
    dp[2][0][0][0] = 0;
    dp[2][1][1][0] = max<int>(0, A[1] - A[0] + 1);
    dp[2][1][0][1] = max<int>(0, A[0] - A[1] + 1);
    for(int i = 2; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int a = 0; a <= 1; a++) {
                for(int b = 0; b <= 1; b++) {
                    int cur = a ? min(A[i - 1], A[i - 2] - 1) : A[i - 1];
                    int nw = b ? min(A[i], cur - 1) : A[i];
                    dp[i + 1][j][b][0] = min(dp[i + 1][j][b][0], dp[i][j][a][b] + (A[i] - nw));
                    if(j < k && b == 0) {
                        dp[i + 1][j + 1][b][1] = min(dp[i + 1][j + 1][b][1],
                                                     dp[i][j][a][b] + max<int>(0, cur - A[i] + 1));
                    }
                }
            }
        }
    }
    for(int i = 1; i <= k; i++) {
        int ans = dp[0][0][0][0];
        for(int a = 0; a <= 1; a++) {
            for(int b = 0; b <= 1; b++) {
                ans = min(ans, dp[n][i][a][b]);
            }
        }
        cout << ans << ' ';
    }
    return 0;
}