#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    long long ans = 0;
    vector <int> ans_v;
    forn (i, 0, n) {
        vector <int> cur(n);
        cur[i] = a[i];
        for (int j = i - 1; j >= 0; --j)
            cur[j] = min(cur[j + 1], a[j]);
        for (int j = i + 1; j < n; ++j)
            cur[j] = min(cur[j - 1], a[j]);
        long long sum = 0;
        forn (j, 0, n)
            sum += cur[j];
        if (sum > ans) {
            ans = sum;
            ans_v = cur;
        }
    }
    //cerr << ans << "\n";
    for (int i : ans_v)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    while (t --> 0)
        solve();
    return 0;
}