#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int> > A(N, vector<int>(M, 0));
    bool ok = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 0) {
                A[i][j] = 1;
                cout << i + 1 << " " << j + 1 << "\n";
            } else {
                ok = true;
                break;
            }
            if (A[N - 1 - i][M - 1 - j] == 0) {
                A[N - 1 - i][M - 1 - j] = 1;
                cout << N - i << " " << M - j << "\n";
            } else {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }
    return 0;
}