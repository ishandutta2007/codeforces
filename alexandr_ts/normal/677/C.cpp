#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 1;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

ll num(char c) {
    if (isdigit(c))
        return c - '0';
    if (isalpha(c))
        if (islower(c))
            return 36 + c - 'a';
        else
            return 10 + c - 'A';
    if (c == '-') return 62;
    return 63;
}

int f(char c) {
    return 6 - __builtin_popcount(num(c));
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    ll ans = 1;
    fr(i, s.size()) {
        ll cur = 1;
        int cnt = f(s[i]);
        fr(j, cnt)
            cur *= 3;
        ans = (ans * cur) % MOD;
    }
    cout << ans;
}