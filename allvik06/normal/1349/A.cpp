#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e18;

int power(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2 == 0) {
        int tmp = power(a, n / 2);
        return tmp * tmp;
    } else {
        return a * power(a, n - 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 1;
    vector<pair<pair<int, int>, int>> flex(200001, {{INF, INF}, 0});
    for (int i = 0; i < n; ++i) {
        int d = 2, cop = a[i];
        if (i == 1 || i == 3) {
            int lol = 1;
        }
        while (d * d <= cop) {
            int kol = 0;
            while (a[i] % d == 0) {
                ++kol;
                a[i] /= d;
            }
            flex[d].second++;
            if (kol < flex[d].first.first) {
                swap(flex[d].first.first, flex[d].first.second);
                flex[d].first.first = kol;
            } else if (kol < flex[d].first.second) {
                flex[d].first.second = kol;
            }
            ++d;
        }
        if (1 < flex[a[i]].first.first) {
            swap(flex[a[i]].first.first, flex[a[i]].first.second);
            flex[a[i]].first.first = 1;
        } else if (1 < flex[a[i]].first.second) {
            flex[a[i]].first.second = 1;
        }
        if (a[i] != 1) {
            ++flex[a[i]].second;
        }
    }
    for (int i = 2; i <= 200000; ++i) {
        if (flex[i].second <= n - 2) continue;
        if (flex[i].second == n) res *= power(i, flex[i].first.second);
        else if (flex[i].second == n - 1) res *= power(i, flex[i].first.first);
    }
    cout << res;
}