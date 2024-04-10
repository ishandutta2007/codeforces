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

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int ans = -1, changes = 0;
    vector<int> lastAns = A;
    for (int step = 1 << 10; step > 0; step /= 2) {
        int mins = ans + step;
        bool works = true;
        int ch = 0;
        map<int, int> pcnt;
        vector<int> pbad;
        for (int i = 0; i < n; ++i) {
            if (A[i] <= m && pcnt[A[i]] < mins) {
                pcnt[A[i]]++;
            } else {
                pbad.push_back(i);
            }
        }
        for (int i = 1; i <= m; ++i) {
            ch += mins - pcnt[i];
        }
        if (ch > SZ(pbad)) {
            continue;
        }
        lastAns = A;
        for (int i = 1; i <= m; ++i) {
            while (pcnt[i] < mins) {
                pcnt[i]++;
                lastAns[pbad.back()] = i;
                pbad.pop_back();
            }
        }
        changes = ch;
        ans = mins;
    }
    cout << ans << ' ' << changes << '\n';
    for (int i = 0; i < n; ++i) {
        cout << lastAns[i] << ' ';
    }
    cout << '\n';
}