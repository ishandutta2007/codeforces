#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define double ld
#define pb push_back
#define fir first
#define sec second
#define int long long

const double EPS = 1e-9;
const double INF = 1e18;

int mx[100], day[100];
int sum = 0;

int get(int u) {
    return (u / 7) * sum + mx[u % 7];
}

void solve() {
    int n;
    cin >> n;
    sum = 0;
    for (int i = 0; i < 7; i++) {
        cin >> day[i];
        sum += day[i];
    }

    mx[0] = 0;
    for (int i = 1; i <= 6; i++) {
        mx[i] = 0;

        for (int j = 0; j < 7; j++) {
            int now = 0;
            int cnt = i;
            for (int l = j; cnt--; l++, l %= 7) {
                now += day[l];
            }
            mx[i] = max(mx[i], now);
        }
    }

    int l = 0;
    int r = 1e12;

    while (r - l > 1) {
        int d = (l + r) / 2;
        if (get(d) >= n)
            r = d; else
            l = d;
    }


    while (get(l) < n)
        l++;

    cout << l << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}