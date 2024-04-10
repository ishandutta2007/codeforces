#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        vector<int> cnt(3);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 'X')
                    cnt[(i+j)%3]++;
            }
        }
        int p = 0;
        for (int i = 1; i < 3; ++i)
            if (cnt[i] < cnt[p])
                p = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i+j)%3 == p && s[i][j] == 'X')
                    cout << 'O';
                else
                    cout << s[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}