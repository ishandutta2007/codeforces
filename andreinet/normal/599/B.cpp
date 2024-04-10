#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    map<int, int> numbers;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (numbers.find(x) != numbers.end()) {
            numbers[x] = 0;
        } else {
            numbers[x] = i + 1;
        }
    }

    vector<int> A(m);
    for (int i = 0; i < m; ++i) cin >> A[i];

    for (int i = 0; i < m; ++i) {
        if (numbers.find(A[i]) == numbers.end()) {
            cout << "Impossible\n";
            return 0;
        }
    }
    
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        int x = A[i];
        if (numbers[x] == 0) {
            cout << "Ambiguity\n";
            return 0;
        }
        ans[i] = numbers[x];
    }

    cout << "Possible\n";
    for (int i = 0; i < m; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}