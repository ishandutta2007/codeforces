#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1000000000000;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector< vector<long long> > v(n + 1, vector<long long>(n + 1, INF));
    for(int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        v[l][r] = min(v[l][r], (long long)c);
    }
    vector< vector<long long> > a(n + 1, vector<long long>(n + 1, INF));
    a[0][0] = 0;
    long long ans = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++)
            a[i][j] = min(a[i][j], a[i - 1][j]);
        for(int j = 1; j <= i; j++) {
            long long q = INF;
            for(int h = i; i - h + 1 <= j; h--) {
                q = min(q, a[h - 1][j - i + h - 1]);
                a[i][j] = min(a[i][j], q + v[h][i]);
            }
            if(j >= k)
                ans = min(ans, a[i][j]);
        }
    }
    cout << (ans == INF? -1 : ans) << '\n';
}