#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define prev asdfsdf
#define x first
#define y second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}

    pt operator - (const pt &r) const {
        return pt(x - r.x, y - r.y);
    }

    bool operator < (const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator == (const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ll cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

ll dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}

ll pwmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

ll inv(ll a, ll mod) {
    return pwmod(a, mod - 2, mod);
}

const int N = 300 * 1000 + 10;
int a[N];
ll s[N];

void solve() {
    int n = nxt();
    int k = nxt();
    forn(i, n + 1) a[i] = nxt();
    for (int i = 0; i <= n; ++i) {
        s[i] = a[i];
    }
    int i;
    for (i = 0; i <= n || (s[i] != 0 && s[i] != -1); ++i) {
        if (s[i] & 1) {
            s[i] -= 1;
            s[i + 1] += s[i] / 2;
            s[i] = 1;
        } else {
            s[i + 1] += s[i] / 2;
            s[i] = 0;
        }
    }
    if (s[i] != 0) ++i;

    int sz = i;
    while (sz > 1 && s[sz - 1] == 0) {
        --sz;
    }
    if (s[sz - 1] == -1) {
        for (i = 0; i < sz; ++i) {
            s[i] *= -1;
        }
        for (i = 0; i < sz; ++i) {
            a[i] *= -1;
        }
        for (i = 0; i < sz || (s[i] != 0); ++i) {
            if (s[i] & 1) {
                s[i] -= 1;
                s[i + 1] += s[i] / 2;
                s[i] = 1;
            } else {
                s[i + 1] += s[i] / 2;
                s[i] = 0;
            }
        }
        sz = i;
        while (sz > 1 && s[sz - 1] == 0) {
            --sz;
        }
    }

//    ll sum = 0;
//    for (i = 0; i <= n; ++i) {
//        sum += a[i] * (1ll << i);
//    }
//    ll s2 = 0;
//    for (i = 0; i < sz; ++i) {
//        s2 += s[i] * (1ll << i);
//    }
//    assert(sum == s2);

    ll ans = 0;
    bool ok = true;
    for (i = 0; i <= n && i < sz && ok; ++i) {
        ll cc = 0;
        int j;
        for (j = 0; i + j < sz && j < 35; ++j) {
            cc += s[i + j] * (1ll << j);
        }
        if (i + j == sz) {
            if (i < n) {
                if (abs(-cc + a[i]) <= k) {
                    ++ans;
                }
            } else {
                if (abs(-cc + a[i]) <= k && abs(-cc + a[i]) != 0) {
                    ++ans;
                }
            }
        }
        if (s[i] != 0) {
            ok = false;
        }
    }
    cout << ans << "\n";
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;//nxt();
    forn(i, t) {
        solve();
    }

    cerr << "Time " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}