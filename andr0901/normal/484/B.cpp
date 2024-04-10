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

const int MAXN = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1);
    a[0] = -1e9;
    forn (i, 1, n + 1)
        cin >> a[i];
    sort(all(a)), a.erase(unique(all(a)), a.end());
    int ans = 0;
    forn (k, 1, sz(a)) {
        int i = a[k];
        for (int j = i; j < MAXN; j += i) {
            ans = max(ans, max(0, *--lower_bound(all(a), j + i) - j));
        }
    }
    cout << ans;
    return 0;
}