#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<string> A(N, string(M, '.'));
    vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> add(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i - 1][j - 1] == 'X') {
                sum[i][j] = 1;
            }
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int ok = 0;
    int ng = max(N, M);
    while (ng - ok > 1) {
        int m = (ok + ng) / 2;
        int len = 2 * m + 1;
        int area = len * len;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                add[i][j] = 0;
            }
        }
        for (int i = 0; i + len <= N; i++) {
            for (int j = 0; j + len <= M; j++) {
                if (sum[i + len][j + len] - sum[i][j + len] - sum[i + len][j] +
                        sum[i][j] ==
                    area) {
                    add[i][j]++;
                    add[i + len][j]--;
                    add[i][j + len]--;
                    add[i + len][j + len]++;
                }
            }
        }
        bool f = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i > 0)
                    add[i][j] += add[i - 1][j];
                if (j > 0)
                    add[i][j] += add[i][j - 1];
                if (i > 0 && j > 0)
                    add[i][j] -= add[i - 1][j - 1];
                if (A[i][j] == 'X' && add[i][j] == 0) {
                    f = false;
                    break;
                }
            }
        }
        if (f) {
            ok = m;
        } else {
            ng = m;
        }
    }
    vector<string> T(N, string(M, '.'));
    cout << ok << endl;
    {
        int len = 2 * ok + 1;
        int area = len * len;
        for (int i = 0; i + len <= N; i++) {
            for (int j = 0; j + len <= M; j++) {
                if (sum[i + len][j + len] - sum[i][j + len] - sum[i + len][j] +
                        sum[i][j] ==
                    area) {
                    T[i + ok][j + ok] = 'X';
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << T[i] << '\n';
    }
    return 0;
}