#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp std::make_pair
#define x first
#define y second

typedef std::pair<int, int> PII;
typedef long long ll;
typedef std::pair<ll, ll> PLL;
typedef long double ld;
typedef std::pair<ld, ld> PLD;
typedef std::pair<double, double> PDD;

using namespace std;


bool check1(const vector<string> &a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            int cnt = 0;
            for (int k = 0; k < 6; ++k) {
                if (a[i][k] == a[j][k]) {
                    ++cnt;
                }
            }
            if (cnt >= 4) return false;
        }
    }
    return true;
}

bool check2(const vector<string> &a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            int cnt = 0;
            for (int k = 0; k < 6; ++k) {
                if (a[i][k] == a[j][k]) {
                    ++cnt;
                }
            }
            if (cnt >= 2) return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 6 << "\n";
        return;
    }
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (check2(a)) {
        cout << 2 << "\n";
    } else if (check1(a)) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}