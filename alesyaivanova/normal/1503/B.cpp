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

const int maxn = 109;
int a[maxn][maxn];
int n;

signed main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int j = 0; j < n * n; j++) {
        int x;
        cin >> x;
        if (x != 1) {
            bool fl = 0;
            for (int i = 0; i < n; i++) {
                for (int e = 0; e < n; e++) {
                    if (!a[i][e] && (i + e) % 2 == 1) {
                        a[i][e] = 1;
                        cout << "1 " << i + 1 << " " << e + 1 << endl;
                        fl = 1;
                        break;
                    }
                }
                if (fl)
                    break;
            }
            if (!fl) {
                int c = 2 + 3 - x;
                for (int i = 0; i < n; i++) {
                    for (int e = 0; e < n; e++) {
                        if (!a[i][e] && (i + e) % 2 == 0) {
                            a[i][e] = c;
                            cout << c << " " << i + 1 << " " << e + 1 << endl;
                            fl = 1;
                            break;
                        }
                    }
                    if (fl)
                        break;
                }
            }
        } else if (x != 2) {
            bool fl = 0;
            for (int i = 0; i < n; i++) {
                for (int e = 0; e < n; e++) {
                    if (!a[i][e] && (i + e) % 2 == 0) {
                        a[i][e] = 2;
                        cout << "2 " << i + 1 << " " << e + 1 << endl;
                        fl = 1;
                        break;
                    }
                }
                if (fl)
                    break;
            }
            if (!fl) {
                int c = 1 + 3 - x;
                for (int i = 0; i < n; i++) {
                    for (int e = 0; e < n; e++) {
                        if (!a[i][e] && (i + e) % 2 == 1) {
                            a[i][e] = c;
                            cout << c << " " << i + 1 << " " << e + 1 << endl;
                            fl = 1;
                            break;
                        }
                    }
                    if (fl)
                        break;
                }
            }
        }
    }
}