#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<vector<int>> A(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        A[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> must(c + 2, 0);
    vector<int> forbidden(c + 2, 0);
    int cntMust = 0;
    for (int i = 1; i < n; ++i) {
        int pos = 0;
        while (pos < SZ(A[i]) && pos < SZ(A[i - 1]) &&
                A[i - 1][pos] == A[i][pos]) {
            pos++;
        }
        if (pos == SZ(A[i]) && pos < SZ(A[i - 1])) {
            cout << "-1\n";
            return 0;
        } else if (pos < SZ(A[i - 1]) && pos < SZ(A[i])) {
            int n1 = A[i - 1][pos];
            int n2 = A[i][pos];
            if (n1 < n2) {
                forbidden[n1 + 1]++;
                forbidden[n2 + 1]--;
            } else {
                swap(n1, n2);
                cntMust++;
                must[n1 + 1]++;
                must[n2 + 1]--;
            }
        }
    }
    for (int i = 1; i <= c; ++i) {
        must[i] += must[i - 1];
        forbidden[i] += forbidden[i - 1];
        if (must[i] == cntMust && forbidden[i] == 0) {
            cout << (c + 1 - i) % c << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;

}