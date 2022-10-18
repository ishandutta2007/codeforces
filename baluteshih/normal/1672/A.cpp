#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x = 0;
        cin >> n;
        while (n--) {
            int y;
            cin >> y;
            if (y % 2 == 0)
                x ^= 1;
        }
        if (x == 1)
            cout << "errorgorn\n";
        else
            cout << "maomao90\n";
    }
}