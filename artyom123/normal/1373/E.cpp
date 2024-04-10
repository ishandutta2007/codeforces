#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<ll> my_pow;

ll gen(int x) {
    if (x == 0) return 0;
    int mn = (x + 8) / 9;
    for (int f = 0; f <= 9 & f <= x; f++) {
        if ((x - f + 8) / 9 == mn - 1) {
            return f * my_pow[mn - 1] + gen(x - f);
        }
    }
}

void init() {
    my_pow.resize(19);
    my_pow[0] = 1;
    for (int i = 1; i <= 18; i++) my_pow[i] = my_pow[i - 1] * 10;
}

int sum(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll ans = INFLL;
        for (int i = 0; i < k; i++) {
            for (ll cnt9 = 1; cnt9 * 9 < n; cnt9++) {
                int kek = n - (cnt9 - 1) * 9 * (i + 1) - sum(9 - i, 9) - sum(0, k - i - 1) - k + i;
                if (kek < 0 || kek % (k + 1) != 0) continue;
                int x = kek / (k + 1);
                for (int last = 0; last <= x && last <= 8; last++) {
                    ll lol = gen(x - last) * 10 + last;
                    for (int j = 0; j < cnt9; j++) lol = lol * 10 + 9;
                    ans = min(ans, lol - i);
                }
            }
        }
        for (int last = 0; last + k <= 9; last++) {
            int kek = n - sum(last, last + k);
            if (kek < 0 || kek % (k + 1) != 0) continue;
            ans = min(ans, gen(kek / (k + 1)) * 10 + last);
        }
        cout << (ans == INFLL ? -1LL : ans) << "\n";
    }
    return 0;
}