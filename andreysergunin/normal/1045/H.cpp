#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

const int nmax = 100500;

int rev[nmax];
int fact[nmax];
int rfact[nmax];

int choose(int n, int k) {
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int get(int n, int k) {
    if (k == 0) {
        if (n == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    return choose(n + k - 1, k - 1);
}

string rg;
int a, b, c, d;

pii solve(int pos) {
    //cout << "!" << pos << endl;
    if (pos == sz(rg)) {
        if (a == 0 && b == 0 && c == 0 && d == 0) {
            return {1, 0};
        } else {
            return {0, 0};
        }
    }
    if (rg[pos] == '0') {
        if (pos) {
            if (rg[pos - 1] == '0') {
                --a;
                if (a < 0) {
                    return {0, 0};
                }
            } else {
                --c;
                if (c < 0) {
                    return {0, 0};
                }
            }
        }
        return solve(pos + 1);
    }
    ll aa = a, bb = b, cc = c, dd = d;
    if (pos) {
        if (rg[pos - 1] == '0') {
            --b;
        } else {
            --d;
        }
    }
    pii ans = {0, 0};
    if (b >= 0 && d >= 0) {
        pii t = solve(pos + 1);
        add(ans.first, t.first);
        add(ans.second, t.second);
    }

    if (pos) {
        a = aa, b = bb, c = cc, d = dd;
        if (pos) {
            if (rg[pos - 1] == '0') {
                --a;
            } else {
                --c;
            }
        }
        if (a >= 0 && c >= 0) {
            if (b == c || b == c + 1) {
                int val = get(a, c + 1);
                mul(val, get(d, b));
                add(ans.second, val);
            }
        }
    }
    
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    rev[1] = 1;
    for (int i = 2; i < nmax; ++i) {
        rev[i] = binpow(i, mod - 2);
    }

    fact[1] = 1;
    rfact[1] = 1;
    fact[0] = rfact[0] = 1;
    for (int i = 2; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = rfact[i - 1];
        mul(rfact[i], rev[i]);
    }

    string x, y;
    cin >> x >> y;

    int p, q, r, s;
    cin >> p >> q >> r >> s;
    int len = p + q + r + s + 1;

    a = p, b = q, c = r, d = s;
    pii t;
    if (sz(y) > len) {
        rg = "";
        for (int i = 0; i < len; ++i) {
            rg += "1";
        }
        t = solve(0);
    } else if (sz(y) == len) {
        rg = y;
        t = solve(0);
    } else {
        t = {0, 0};
    }

    int ans = t.first;
    add(ans, t.second);
    //cout << "!" << t.first << " " << t.second << endl;

    a = p, b = q, c = r, d = s;
    if (sz(x) > len) {
        rg = "";
        for (int i = 0; i < len; ++i) {
            rg += "1";
        }
        t = solve(0);
        sub(ans, t.first);
        sub(ans, t.second);
    } else if (sz(x) == len) {
        rg = x;
        t = solve(0);
        sub(ans, t.second);
    }

    cout << ans << "\n";
    
}