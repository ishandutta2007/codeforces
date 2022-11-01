#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

vector<int> tryMatch(int n, const vector<pair<int, int>>& nmb, int maxValue) {
    vector<bool> used(n, false);
    vector<int> ret;
    int lastUsed = -1;
    for (int i = SZ(nmb) - 1; i >= 0; --i) {
        if (nmb[i].first > maxValue) {
            continue;
        }
        if (nmb[i].first == lastUsed) {
            continue;
        }
        if (!used[nmb[i].second]) {
            used[nmb[i].second] = true;
            ret.push_back(nmb[i].first);
            lastUsed = nmb[i].first;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            return vector<int>(1, -1);
        }
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
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> A;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (x > 0) {
            A.push_back(make_pair(x, i));
            x /= 2;
        }
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for (int step = 1 << 30; step > 0; step /= 2) {
        vector<int> B = tryMatch(n, A, ans + step);
        if (SZ(B) == 1 && B[0] == -1) {
            ans += step;
        }
    }
    vector<int> B = tryMatch(n, A, ans + 1);
    for (int p: B) {
        cout << p << ' ';
    }
    cout << '\n';
}