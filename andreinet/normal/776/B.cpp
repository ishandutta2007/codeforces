#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;

vector<int> diff[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n++;
    int vmax = 0;
    for (int i = 2; i <= n; ++i) {
        diff[i].push_back(0);
    }
    vector<int> ans(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        sort(diff[i].begin(), diff[i].end());
        diff[i].erase(unique(diff[i].begin(), diff[i].end()), diff[i].end());
        int j = 1;
        while (j < SZ(diff[i]) && diff[i][j] == diff[i][j - 1] + 1) {
            j++;
        }
        ans[i] = diff[i][j - 1] + 1;
        vmax = max(vmax, ans[i]);
        if (SZ(diff[i]) == 1) {
            for (int j = i + i; j <= n; j += i) {
                diff[j].push_back(ans[i]);
            }
        }
    }
    cout << vmax << '\n';
    for (int i = 2; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}