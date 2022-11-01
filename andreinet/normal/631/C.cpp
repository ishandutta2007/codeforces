#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 200005;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<pair<int, int>> ops;
    while (m-- > 0) {
        int t, r;
        cin >> t >> r;

        while (!ops.empty() && r >= ops.back().first) {
            ops.pop_back();
        }
        ops.push_back(make_pair(r, t));
    }
    int cmax = ops.front().first;
    ops.push_back(make_pair(0, 0));
    sort(A.begin(), A.begin() + cmax);
    vector<int> B;
    int l = 0, r = cmax;
    for (int i = 0; i < SZ(ops) - 1; ++i) {
        int d = ops[i].first - ops[i + 1].first;
        if (ops[i].second == 2) {
            while (d-- > 0) {
                B.push_back(A[l++]);
            }
        } else {
            while (d-- > 0) {
                B.push_back(A[--r]);
            }
        }
    }
    reverse(B.begin(), B.end());
    B.insert(B.end(), A.begin() + cmax, A.end());

    for (int p: B) {
        cout << p << ' ';
    }
    cout << '\n';
}