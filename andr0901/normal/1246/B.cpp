#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

int k;

vector <pii> get(int x) {
    vector <pii> ans;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ans.pb({i, 0});
            while (x % i == 0) {
                ans.back().sc++;
                x /= i;
            }
        }
    }
    if (x > 1) {
        ans.eb(x, 1);
    }
    return ans;
}

vector <pii> normalize(const vector <pii>& a) {
    vector <pii> ans;
    for (pii i : a)
        if (i.sc % k)
            ans.eb(i.fs, i.sc % k);
    return ans;
}

vector <pii> rev(const vector <pii>& a) {
    vector <pii> ans;
    for (pii i : a)
        ans.eb(i.fs, (k - i.sc) % k);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    map <vector <pii>, int> a;
    int n;
    cin >> n >> k;
    ll ans = 0;
    forn (i, 0, n) {
        int x;
        cin >> x;
        auto b = normalize(get(x));
        ans += a[normalize(rev(b))];
        a[b]++;
    }
    cout << ans;
    return 0;
}