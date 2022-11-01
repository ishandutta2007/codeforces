#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 15, KMAX = 500005, INF = 0x3f3f3f3f;

int A[KMAX];
int pnext[KMAX][NMAX];
map<string, int> words;

string pattern(int n) {
    string result(n + 4, 0);
    result[0] = '[';
    result[1] = ':';
    for (int i = 0; i < n; ++i)
        result[2 + i] = '|';
    result[n + 2] = ':';
    result[n + 3] = ']';
    return result;
}

int dp[1 << NMAX][NMAX * NMAX];

int solve() {
    int n = SZ(words), m;
    cin >> m;

    int k = 0;
    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        auto it = words.find(word);
        if (it != words.end()) {
            A[++k] = it->second;
        }
    }
    
    for (int j = 0; j < n; ++j)
        pnext[k][j] = k + 1;
    for (int i = k - 1; i >= 0; --i) {
        memcpy(pnext[i], pnext[i + 1], sizeof pnext[i]);
        pnext[i][A[i + 1]] = i + 1;
    }
    
    memset(dp, INF, sizeof dp);
    dp[0][0] = 0;

    int limInv = n * (n - 1) / 2;
    for (int conf = 0; conf < (1 << n); ++conf) {
        for (int inv = 0; inv <= limInv; ++inv) {
            if (dp[conf][inv] > k) continue;
            int p = dp[conf][inv], ninv = inv;
            for (int i = n - 1; i >= 0; --i) {
                if ((conf & (1 << i)) == 0) {
                    dp[conf | (1 << i)][ninv] = min(dp[conf | (1 << i)][ninv],
                            pnext[p][i]);
                } else {
                    ninv++;
                }
            }
        }
    }
    int pos = 0;
    while (pos <= limInv && dp[(1 << n) - 1][pos] > k)
        ++pos;
    return limInv + 1 - pos;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        words[word] = i;
    }

    int m;
    cin >> m;

    int ans = 0, pos = -1;
    for (int i = 0; i < m; ++i) {
        int p = solve();
        if (p > ans) {
            ans = p;
            pos = i + 1;
        }
    }

    if (ans == 0) cout << "Brand new problem!\n";
    else {
        cout << pos << '\n';
        cout << pattern(ans) << '\n';
    }
}