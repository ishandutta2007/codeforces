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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector <int> a(2);
        vector <int> lens(n);
        forn (i, 0, n) {
            string s;
            cin >> s;
            for (char j : s)
                a[j - '0']++;
            lens[i] = sz(s);
        }
        sort(all(lens), [](int a, int b) {
            if (a % 2 != b % 2)
                return a % 2 < b % 2;
            return a < b;
        });
        int ans = 0;
        forn (i, 0, n) {
            bool ok = true;
            forn (j, 0, lens[i] / 2) {
                bool same = false;
                forn (k, 0, 2) {
                    if (a[k] >= 2) {
                        a[k] -= 2;
                        same = true;
                        break;   
                    }
                }
                if (!same) {
                    a[0] -= 1;
                    a[1] -= 1;
                    ok = false;
                }
            }
            if (lens[i] % 2) {
                forn (k, 0, 2) {
                    if (a[k] >= 1) {
                        a[k] -= 1;
                        break;
                    }
                }
            }
            ans += ok;
            /*cout << ans << ":\n";
            for (int j : a)
            cout << j << " ";
            cout << "\n";*/
        }
        cout << ans << "\n";
    }
    return 0;
}