#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

bool isPalindrome(const string& s) {
    bool ok = true;
    for (int i = 0; i < SZ(s); ++i) {
        ok &= s[i] == s[SZ(s) - i - 1];
    }
    return ok;
}

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

    vector<pair<string, int>> A;
    vector<pair<string, int>> pals;
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        int p;
        cin >> s >> p;
        if (isPalindrome(s)) {
            pals.push_back(make_pair(s, -p));
        } else {
            A.push_back(make_pair(s, -p));
        }
    }
    sort(A.begin(), A.end());
    n = SZ(A);
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && A[i].first == A[j].first; ++j) {

        }
        string rev = A[i].first;
        reverse(rev.begin(), rev.end());
        int i1 = lower_bound(A.begin(), A.end(), make_pair(rev, -100000)) - A.begin();
        int j1 = upper_bound(A.begin(), A.end(), make_pair(rev, 100000)) - A.begin();
        if (i1 < i) {
            continue;
        }
        for (int k = 0; i + k < j && i1 + k < j1; ++k) {
            if (-A[i + k].second - A[i1 + k].second > 0) {
                ans += -A[i + k].second - A[i1 + k].second;
            } else {
                break;
            }
        }
    }
    sort(pals.begin(), pals.end());
    int maxAdd = 0;
    for (int i = 0; i < SZ(pals); ) {
        if (i < SZ(pals) - 1 && pals[i].first == pals[i + 1].first) {
            int add = -pals[i].second - pals[i + 1].second;
            if (add > 0) {
                ans += add;
                maxAdd = max(maxAdd, - (-pals[i + 1].second));
                i += 2;
            } else {
                maxAdd = max(maxAdd, -pals[i].second);
                i += 1;
            }
        } else {
            maxAdd = max(maxAdd, -pals[i].second);
            i += 1;
        }
    }
    ans += maxAdd;

    cout << ans << '\n';
}