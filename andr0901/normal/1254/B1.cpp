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

int n;
long long ans = 1e18;

int my_abs(int x, int y) {
    if (x < y)
        return y - x;
    else
        return x - y;
}

void go(int x, vector <int> a) {
    //cout << x << "\n";
    long long cur = 0;
    vector <int> idx;
    forn (i, 0, n) {
        if (a[i])
            idx.pb(i);
        if (idx.size() == x) {
            int t = idx[sz(idx) / 2];
            for (int j : idx)
                cur += my_abs(j, t);
            idx.clear();
        }   
    }
    ans = min(ans, cur);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    forn (i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            if (i != 1)
                go(i, a);
            if (sum / i != 1)
                go(sum / i, a);
        }
    }
    if (ans == 1e18)
        cout << -1;
    else
        cout << ans;
    return 0;
}