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

    string vowels = "aeiouy";
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cin.get();
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        int cnt = 0;
        for (char c: vowels) {
            cnt += count(s.begin(), s.end(), c);
        }
        if (cnt != A[i]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n": "NO\n");
}