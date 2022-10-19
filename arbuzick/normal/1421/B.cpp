#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        if (a[0][1] == a[1][0]) {
            int c = 0;
            if (a[n-1][n-2] == a[0][1])
                c++;
            if (a[n-2][n-1] == a[0][1])
                c++;
            cout << c << '\n';
            if (a[n-1][n-2] == a[0][1])
                cout << n << ' ' << n-1 << '\n';
            if (a[n-2][n-1] == a[0][1])
                cout << n-1 << ' ' << n << '\n';
            continue;
        }
        if (a[n-1][n-2] == a[n-2][n-1]) {
            int c = 0;
            if (a[n-1][n-2] == a[0][1])
                c++;
            if (a[n-2][n-1] == a[1][0])
                c++;
            cout << c << '\n';
            if (a[n-1][n-2] == a[0][1])
                cout << 1 << ' ' << 2 << '\n';
            if (a[n-2][n-1] == a[1][0])
                cout << 2 << ' ' << 1 << '\n';
            continue;
        }
        cout << 2 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        if (a[n-1][n-2] == a[1][0])
            cout << n << ' ' << n-1 << '\n';
        else
            cout << n-1 << ' ' << n << '\n';
    }
    return 0;
}