#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

struct kek{
    int cnt, ind, t;
    kek(){}
    kek(int cnt, int ind, int t) : cnt(cnt), ind(ind), t(t) {}
    bool operator< (const kek &k) const {
        if (cnt != k.cnt) return cnt < k.cnt;
        if (t < k.t) return t < k.t;
        return ind < k.ind;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k % n == 0) cout << 0 << "\n";
        else cout << 2 << "\n";
        vector<int> cnt(n);
        if (k % n == 0) {
            for (auto &c : cnt) c = k / n;
        } else {
            for (int i = 0; i < k % n; i++) cnt[i] = k / n + 1;
            for (int i = k % n; i < n; i++) cnt[i] = k / n;
        }
        set<kek> lol;
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            lol.insert(kek(0, i, -1));
        }
        for (int i = 0; i < n; i++) {
            while (cnt[i]) {
                kek now = *lol.begin();
                lol.erase(lol.begin());
                ans[i][now.ind] = 1;
                lol.insert(kek(now.cnt + 1, now.ind, i));
                cnt[i]--;
            }
        }
        for (auto &c : ans) {
            for (auto &l : c) cout << l;
            cout << "\n";
        }
    }
    return 0;
}