#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

const int N = 1e2 + 1;
const int M = 1e7 + 1;;
const ll INF = 1000000ull * 1000000ull * 1000000ull + 1ull;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

ll d[N][N];
ll pows[N];

ll toInt(string s, ll l, ll r) {
    string t = s.substr(l, r - l + 1);
    reverse(t.begin(), t.end());
    ll ans = 0;
    fr(i, t.size())
        ans = ans * 10 + t[i] - '0';
    return ans;
}

bool ok(string s, ll l, ll r, ll n) {
    string t = s.substr(l, r - l + 1);
    reverse(t.begin(), t.end());
    if (t[0] == '0' && l == r) return true;
    if (t[0] == '0') return false;
    if (t.size() > 10) return false;
    ll x = toInt(s, l, r);
    return x < n;
}

bool mult(ll a, ll b) {
    ld a1 = a, b1 = b;
    return a1 * b1 < 1e18;
}

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    ll n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    int m = s.size();
    pows[0] = 1;
    frab(i, 1, m + 1)
        pows[i] = pows[i - 1] * n;

    fr(i, m + 1)
        fill(d[i], d[i] + m + 1, INF);
    d[0][0] = 0;
    fr(i, m)
        fr(j, m)
            if (d[i][j] != INF) {
                frab(i1, i + 1, m + 1)
                    if (ok(s, i, i1 - 1, n)) {
                        if (!mult(toInt(s, i, i1 - 1), pows[j]))
                            continue;
                        ll add = toInt(s, i, i1 - 1) * pows[j];
                        d[i1][j + 1] = min(d[i1][j + 1], d[i][j] + add);
                    }
            }
    ll ans = INF;
    fr(i, m + 1)
        ans = min(ans, d[m][i]);
    cout << ans;
}