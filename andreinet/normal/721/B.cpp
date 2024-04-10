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

    int n, k;
    cin >> n >> k;

    vector<string> A(n);
    for (string& p: A) {
        cin >> p;
    }
    sort(A.begin(), A.end(), [](const string& a, const string& b) -> bool {
        return a.length() < b.length();
    });
    string pass;
    cin >> pass;
    int cnt1 = 0, cnt2 = 0;
    for (string& p: A) {
        if (SZ(p) == SZ(pass)) {
            break;
        }
        cnt1++;
    }
    for (string& p: A) {
        if (SZ(p) == SZ(pass)) {
            cnt2++;
        }
    }
    int64_t fans = cnt1 + 5 * (cnt1 / k) + 1;
    int64_t sans = cnt1 + cnt2 + 5 * ((cnt1 + cnt2 - 1) / k);
    cout << fans << ' ' << sans << '\n';
}