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

    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> A, B;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        A.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        B.insert(x);
    }

    multiset<int> C = B;
    for (int x: B) {
        if (A.find(x) != A.end()) {
            A.erase(A.find(x));
            C.erase(C.find(x));
        }
    }

    for (auto it = A.rbegin(); it != A.rend(); ++it) {
        int x = *it;
        auto xit = C.lower_bound(x);
        if (xit == C.end()) {
            cout << "YES\n";
            return 0;
        } else {
            C.erase(xit);
        }
    }
    cout << "NO\n";
}