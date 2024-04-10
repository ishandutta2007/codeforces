#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int> > A(N, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[j][i];
        }
    }
    int res = M + 1;
    vector<int> X;
    for (int i = 0; i < N - 1; i++) {
        vector<pair<int, int> > vp;
        int sum = 0;
        for (int j = 0; j < M; j++) {
            sum += A[i][j] - A[N - 1][j];
            vp.emplace_back(A[i][j] - A[N - 1][j], j);
        }
        sort(vp.begin(), vp.end());
        if (sum >= 0) {
            res = 0;
            X.clear();
        }
        vector<int> tmp;
        for (int j = 0; j < M; j++) {
            sum -= vp[j].first;
            tmp.push_back(vp[j].second);
            if (sum >= 0) {
                if (res > j + 1) {
                    res = j + 1;
                    X = tmp;
                }
                break;
            }
        }
    }

    cout << res << endl;
    for (int i = 0; i < X.size(); i++) {
        if (i > 0) cout << " ";
        cout << X[i] + 1;
    }
    cout << endl;
}