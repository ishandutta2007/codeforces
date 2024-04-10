#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 100005;

int n;
vi a[N];
bool check[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l; cin >> l;
        for (int j = 1; j <= l; j++) {
            int e; cin >> e;
            a[i].pb(e);
        }
    }
    int ans = 0;
    vi h , t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < (int) a[i].size(); j++) {
            if (a[i][j] > a[i][j - 1]) {
                ans++;
                check[i] = 1;
                break;
            }
        }
        if (check[i] == 1) continue;
        t.pb(a[i].back());
    }
    sort(all(t));
    long long res = 1LL * n * n - 1LL * (n - ans) * (n - ans);
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        res += lower_bound(all(t), a[i][0]) - t.begin();
    }
    cout << res;
    return 0;
}