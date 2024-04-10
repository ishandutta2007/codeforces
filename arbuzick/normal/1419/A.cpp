#include <bits/stdc++.h>
#define int long long
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
        string s;
        cin >> s;
        if (n%2 == 1) {
            bool f = 0;
            for (int i = 0; i < n; i += 2)
                f = f||((s[i]-'0')%2);
            if (f)
                cout << "1\n";
            else
                cout << "2\n";
        } else {
            bool f = 0;
            for (int i = 1; i < n; i += 2)
                f = f||((s[i]-'0')%2 == 0);
            if (!f)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }
    return 0;
}