#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int a[maxn];
int b[maxn];
int c[maxn];
int n;

void solve() {
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        a[i] = (s[i] == '1');
    int cnt1 = 0;
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i])
            cnt1++;
        else
            cnt0++;
    }
    if (cnt0 % 2 == 1 || cnt1 % 2 == 1) {
        cout << "NO\n";
        return;
    }
    int cur = 0;
    int bal1 = 0, bal2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            if (cur < cnt1 / 2) {
                b[i] = 1;
                c[i] = 1;
                bal1++;
                bal2++;
                cur++;
            } else {
                b[i] = -1;
                c[i] = -1;
                bal1--;
                bal2--;
            }
        } else {
            if (bal1 > bal2) {
                b[i] = -1;
                c[i] = 1;
                bal1--;
                bal2++;
            } else {
                b[i] = 1;
                c[i] = -1;
                bal1++;
                bal2--;
            }
        }
        if (bal1 < 0 || bal2 < 0) {
            cout << "NO\n";
            return;
        }
    }
    if (bal1 != 0 || bal2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            if (b[i] == 1)
                cout << "(";
            else
                cout << ")";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            if (c[i] == 1)
                cout << "(";
            else
                cout << ")";
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}