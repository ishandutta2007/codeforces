#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string f = "Ashishgup", s = "FastestFinger";
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << s << "\n";
            continue;
        }
        if (n == 2) {
            cout << f << "\n";
            continue;
        }
        if (n % 2 == 1) {
            cout << f << "\n";
            continue;
        }
        int lol = 1;
        while (n % (lol * 2) == 0) lol *= 2;
        if (n == lol) {
            cout << s << "\n";
            continue;
        }
        n /= lol;
        int cnt = 0;
        for (int i = 3; i * i <= n; i++) {
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
        }
        if (n > 1) cnt++;
        if (lol == 2) cnt--;
        if (cnt == 0) cout << s << "\n";
        else cout << f << "\n";
    }
    return 0;
}