#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

string inverse(string s) {
    string ret(SZ(s), 0);
    for (int i = 0; i < SZ(s); ++i) {
        ret[i] = s[i] == '*' ? '+': '*';
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> ans = {"+"};
    for (int i = 1; i <= n; ++i) {
        vector<string> nans = ans;
        int m = SZ(ans);
        for (int i = 0; i < m; ++i) {
            string p = inverse(ans[i]);
            nans.push_back(p);
        }
        for (int i = 2 * m - 1; i >= 0; --i) {
            nans[i] += nans[i % m];
        }
        ans = nans;
    }

    for (const string& p: ans)
        cout << p << '\n';
}