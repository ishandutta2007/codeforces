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

    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> lastTimeR(n, -1), lastColorR(n, 0);
    vector<int> lastTimeC(m, -1), lastColorC(m, 0);
    for (int i = 0; i < q; ++i) {
        int type, x, a;
        cin >> type >> x >> a;
        x--;
        if (type == 1) {
            lastTimeR[x] = i;
            lastColorR[x] = a;
        } else {
            lastTimeC[x] = i;
            lastColorC[x] = a;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lastTimeR[i] > lastTimeC[j]) {
                cout << lastColorR[i] << ' ';
            } else {
                cout << lastColorC[j] << ' ';
            }
        }
        cout << '\n';
    }
}