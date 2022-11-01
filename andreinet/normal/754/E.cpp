#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 405;

bitset<NMAX> let[NMAX][NMAX][26];

string toString(const bitset<NMAX>& a, int len) {
    string s = a.to_string();
    reverse(s.begin(), s.end());
    s.resize(len);
    return s;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                int pos = (j - k + m) % m;
                let[i][pos][A[i][j] - 'a'].set(k);
            }
        }
    }
    int h, w;
    cin >> h >> w;
    vector<string> B(h);
    for (int i = 0; i < h; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < n; ++i) {
        bitset<NMAX> res;
        res.set();
        for (int i1 = 0; i1 < h; ++i1) {
            for (int j1 = 0; j1 < w; ++j1) {
                if (B[i1][j1] != '?') {
                    res &= let[(i + i1) % n][j1 % m][B[i1][j1] - 'a'];
                }
            }
        }
        cout << toString(res, m) << '\n';
    }
}