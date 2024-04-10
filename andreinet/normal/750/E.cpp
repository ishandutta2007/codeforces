#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int INF = 0x3f3f3f3f;
const int NMAX = 200005;

int aint[4 * NMAX][4][4];

const int POS[] = {2, 3, 1, 0, 0, 0, 4, 0, 0, 0, 0};

void build(int node, int left, int right, const string& s) {
    if (left == right) {
        int pos = POS[s[left] - '0'];
        for (int i = 0; i < 4; ++i) {
            aint[node][i][i] = 0;
        }
        if (pos > 0 && pos < 4) {
            aint[node][pos - 1][pos] = 0;
        }
        if (pos > 0) {
            aint[node][pos - 1][pos - 1] = 1;
        }
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid, s);
        build(2 * node + 2, mid + 1, right, s);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    aint[node][i][j] = min(aint[node][i][j],
                            aint[2 * node + 1][i][k] + aint[2 * node + 2][k][j]);
                }
            }
        }
    }
}

int xq[4];

void query(int node, int left, int right, int lq, int rq) {
    if (lq <= left && right <= rq) {
        int nq[4];
        memset(nq, INF, sizeof nq);
        for (int i = 0; i < 4; ++i) {
            for (int j = i; j < 4; ++j) {
                nq[j] = min(nq[j], xq[i] + aint[node][i][j]);
            }
        }
        memcpy(xq, nq, sizeof xq);
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) {
            query(2 * node + 1, left, mid, lq, rq);
        }
        if (rq > mid) {
            query(2 * node + 2, mid + 1, right, lq, rq);
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    memset(aint, INF, sizeof aint);
    build(0, 0, n - 1, s);

    vector<int> occ[10];
    for (int i = 0; i < n; ++i) {
        occ[s[i] - '0'].push_back(i);
    }
    
    while (q-- > 0) {
        int left, right;
        cin >> left >> right;
        left--; right--;

        int p7 = upper_bound(occ[7].begin(), occ[7].end(), right) - occ[7].begin() - 1;
        if (p7 == -1 || occ[7][p7] < left) {
            cout << "-1\n";
            continue;
        }
        p7 = occ[7][p7];

        memset(xq, INF, sizeof xq);
        xq[0] = 0;
        query(0, 0, n - 1, left, p7 - 1);
        int ans = xq[3];
        if (ans == INF) {
            ans = -1;
        } else {
            ans += upper_bound(occ[6].begin(), occ[6].end(), right) -
                lower_bound(occ[6].begin(), occ[6].end(), p7);
        }
        cout << ans << '\n';
    }
}