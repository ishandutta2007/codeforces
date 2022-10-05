#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const ll p = 7169239;

int n, i, j;
string s;
vector<vector<int>> dp, sum;
vector<ll> h, hh, ppow;
bool viv = false;

ll rrand() {
    vector<ll> v;
    for (ll i = 0 ; i < 10; i++)
        v.push_back(rand() % 1000);
    ll res = 0;

    for (ll i = 0; i < 10; i += 2) {
        res *= v[i];
        res += v[i+1];
        res %= mod;
    }
    return res;
}

void prepare() {
    for (ll i = 0; i < 10; i++)
        hh.push_back(rrand());
    h.push_back(0);
    for (ll i = 0; i < n; i++) {
        h.push_back(h.back()*p);
        h.back() += hh[s[i] - '0'];
        h.back() %= mod;
    }
    ppow.push_back(1);
    for (ll i = 0; i < 2 * n; i++)
        ppow.push_back(ppow.back() * p), ppow.back() %= mod;
}

bool same(ll a, ll b, ll c, ll d) {
    int h1 = h[b+1];
    h1 -= (h[a] * ppow[b - a + 1]) % mod;
    if (h1 < 0)
        h1 += mod;
    int h2 = h[d+1];
    h2 -= (h[c] * ppow[d - c + 1]) % mod;
    if (h2 < 0)
        h2 += mod;
    return h1 == h2;
}

int com(ll a, ll b, ll c, ll d) {
    int l = 0;
    int r = b - a + 1;
    while (l + 1 != r) {
        int mi = l + r >> 1;
        if (same(a, a + mi - 1, c, c + mi - 1))
            l = mi;
        else
            r = mi;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(0));
    cin >> n;
    cin >> s;
    prepare();
    dp.resize(n+1);
    for (auto &l : dp)
        l.resize(n + 1);
    sum.resize(n+1);
    for (auto &l : sum)
        l.resize(n + 1);
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
        sum[0][i] = 1;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= i + 1; len++) {
            dp[i+1][len] = sum[i + 1 - len][len-1];
            if (dp[i + 1 - len][len] != 0) {
                int s1 = i - len + 1;
                int s2 = s1 - len;
                int pref = com(s2, s1-1, s1, s1 + len - 1);
                bool need = false;
                if (pref != len)
                    need = s[s2 + pref] < s[s1 + pref];
                if (need)
                    dp[i+1][len] += dp[i + 1 - len][len];
                if (dp[i+1][len] >= mod)
                    dp[i+1][len] -= mod;
            }
//            cout << "dp[" << i+1 << "][" << len << "] = " << dp[i+1][len] << endl;
            if (s[i+1-len] == '0')
                dp[i+1][len] = 0;
//            cout << "dp[" << i+1 << "][" << len << "] = " << dp[i+1][len] << endl;
        }

        sum[i+1][0] = dp[i+1][0];
        for (int j = 1; j <= n; j++) {
            sum[i+1][j] = (sum[i+1][j-1] + dp[i+1][j]);
            if (sum[i+1][j] >= mod)
                sum[i+1][j] -= mod;
        }
    }

    cout << sum[n][n];





    return 0;
}