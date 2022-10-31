#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int MOD = 1e9 + 7;
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    vector <int> suf(n + 1, 0);
    vector <int> pow(1e5 + 1);
    pow[0] = 1;
    forn (i, 1, pow.size())
        pow[i] = (2 * pow[i - 1]) % MOD;
    forn (i, 1, n + 1) {
        char c;
        cin >> c;
        if (c == '1')
            a[i] = 0;
        else
            a[i] = 1;
        suf[i] = suf[i - 1] + a[i];
    }
    /*forn (i, 0, n + 1)
        cout << suf[i] << " ";*/
    while (q --> 0) {
        int a, b;
        cin >> a >> b;
        int t = suf[b] - suf[a - 1];
        cout << (pow[b - a + 1] - pow[t] + MOD) % MOD << "\n";
    }
    return 0;
}