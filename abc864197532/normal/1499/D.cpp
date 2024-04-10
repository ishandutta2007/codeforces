#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) {\
    for (auto a : x) cout << a << ' ';\
    cout << endl;\
}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 20000087, logN = 17;

int p[N];

void build() {
    for (int i = 2; i < N; ++i) if (!p[i]) {
        for (int j = i; j < N; j += i) p[j]++;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t;
    cin >> t;
    while (t--) {
        int c, d, x;
        cin >> c >> d >> x;
        /*
         * a = gA b = gB
         * cgAB - dg = x
         * g(cAB - d) = x
         */
        lli ans = 0;
        for (int i = 1; i * i <= x; ++i) if (x % i == 0) {
            {
                int tmp = x / i;
                if ((tmp + d) % c == 0) {
                    int AB = (tmp + d) / c;
                    ans += 1 << p[AB];
                    // cAB = tmp + d
                }
            }
            if (i * i != x) {
                int tmp = i;
                if ((tmp + d) % c != 0) continue;
                int AB = (tmp + d) / c;
                ans += 1 << p[AB];
                // cAB = tmp + d
            }
        }
        cout << ans << endl;
    }
}