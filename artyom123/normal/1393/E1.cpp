#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

struct my_hash {
    const ll mod = 1e9 + 7, p = 101;
    vector<ll> h, my_pow;
    int n;
    my_hash(){}
    my_hash(string s) {
        n = s.size();
        h.resize(n + 1);
        my_pow.resize(n + 1);
        my_pow[0] = 1;
        for (int i = 1; i <= n; i++) {
            my_pow[i] = (my_pow[i - 1] * p) % mod;
            h[i] = (h[i - 1] * p + s[i - 1]) % mod;
        }
    }
    int get(int i, int len) {
        if (i == n || i >= len) return h[len];
        return (h[len + 1] - h[i + 1] * my_pow[len - i] + h[i] * my_pow[len - i] + mod * mod) % mod;
    }
};

vector<my_hash> lol;
vector<string> l;

char get_char(string &s, int i, int j) {
    if (j < i) return s[j];
    j++;
    if (j == (int)s.size()) return '.';
    return s[j];
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    int len1 = lol[a.fi].n - (a.se != lol[a.fi].n);
    int len2 = lol[b.fi].n - (b.se != lol[b.fi].n);
    int left = 0, right = min(len1, len2) + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (lol[a.fi].get(a.se, mid) == lol[b.fi].get(b.se, mid)) left = mid;
        else right = mid;
    }
    if (left == len1 && left == len2) {
        return a.fi < b.fi;
    }
    return get_char(l[a.fi], a.se, left) < get_char(l[b.fi], b.se, left);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    l.resize(n);
    vector<vector<int>> dp(n);
    vector<pii> kek;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        lol.pb(l[i]);
        dp[i].resize(l[i].size() + 1);
        for (int j = 0; j <= (int)l[i].size(); j++) kek.pb(i, j);
    }
    vector<vector<pii>> pos(n);
    sort(all(kek), cmp);
    for (auto &c : kek) {
        pos[c.fi].pb(c);
        if (c.fi + 1 < n) pos[c.fi + 1].pb(c);
    }
    for (auto &c : dp[0]) c = 1;
    for (int i = 1; i < n; i++) {
        int now = 0;
        for (auto &c : pos[i]) {
            if (c.fi == i - 1) add(now, dp[i - 1][c.se]);
            if (c.fi == i) add(dp[i][c.se], now);
        }
    }
    int ans = 0;
    for (auto &c : dp[n - 1]) add(ans, c);
    cout << ans;
    return 0;
}