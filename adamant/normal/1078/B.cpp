#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define int int64_t

const int maxn = 1e2;

typedef double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

int b[maxn + 1];

int dp[101][10001];
int old[101][10001];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //int n = 100;
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++) {
        //a[i] = 1 + rand() % 100;
        cin >> a[i];
        b[a[i]]++;
    }
    int sum = accumulate(a, a + n, 0);
    dp[0][0] = 1;
    for(int i = 1; i <= maxn; i++) {
        if(!b[i]) {
            continue;
        }
        memcpy(old, dp, sizeof(old));
        for(int j = 1; j <= n; j++) {
            int mx = min(j, b[i]);
            for(int s = i; s <= sum; s++) {
                //dp[j][s] = old[j][s] + old[j - 1][s - i] + ... + old[j - mx][s - mx * i];
                dp[j][s] = dp[j - 1][s - i] + old[j][s];
                if(s >= (mx + 1) * i && j >= mx + 1) {
                    dp[j][s] -= old[j - (mx + 1)][s - (mx + 1) * i];
                }
            }
        }
        for(int j = 1; j <= n; j++) {
            for(int s = i; s <= sum; s++) {
                dp[j][s] = min(dp[j][s], int(2));
            }
        }
    }
    int types = set<int>(a, a + n).size();
    int ans = 0;
    for(int i = 0; i <= maxn; i++) {
        for(int j = 1; j <= b[i]; j++) {
            if(dp[j][j * i] == 1) {
                ans = max(ans, j);
            }
        }
    }
    if(types <= 2) {
        ans = n;
    }
    cout << ans << endl;
    cerr << clock() / double(CLOCKS_PER_SEC) << endl;
    return 0;
}