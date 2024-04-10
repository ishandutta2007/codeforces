#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

bool check(const vector<int>& A) {
    multiset<int> s;
    int cnt = 0;
    for (int p: A) {
        if (s.find(p) != s.end()) {
            cnt++;
        } else {
            s.insert(p);
        }
    }
    return cnt <= (SZ(A) + 2) / 3;
}

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
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());

    vector<int> B(n, 0), C(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i < (n + 2) / 3) {
            B[i] = i;
            C[i] = A[i].first - B[i];
        } else if (i < (n + 2) / 3 * 2) {
            C[i] = i;
            B[i] = A[i].first - C[i];
        } else {
            C[i] = n - 1 - i;
            B[i] = A[i].first - C[i];
        }
    }
    
    vector<int> rb(n), rc(n);
    for (int i = 0; i < n; ++i) {
        rb[A[i].second] = B[i];
        rc[A[i].second] = C[i];
    }
    
    if (check(rb) && check(rc)) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << rb[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            cout << rc[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
}