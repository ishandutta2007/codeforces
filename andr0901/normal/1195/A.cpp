#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int nxt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = nxt(), k = nxt();
    vector <int> a(k);
    int ans = 0, cnt = (n + 1) / 2;
    forn (i, 0, n) {
        int t = nxt() - 1;
        a[t]++;
        if (a[t] % 2 == 0) {
            ans += 2;
            cnt--;
        }
    }
    forn (i, 0, k) {
        if (a[i] % 2 && cnt) {
            cnt--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}