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
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        set<int> used;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (used.count(b[i]))
                ans = 1;
            used.insert(b[i]);
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}