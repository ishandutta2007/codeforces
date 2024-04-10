#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 200500;

const int mod1 = 999999797;
const int mod2 = 999999929;
const int base1 = 10099;
const int base2 = 4243;

int p1[maxn];
int p2[maxn];

void genp() {
    p1[0] = p2[0] = 1;
    forn(i, maxn) if (i) {
        p1[i] = (i64)p1[i-1]*base1 % mod1;
        p2[i] = (i64)p2[i-1]*base2 % mod2;
    }
}

struct Int {
    int v1, v2;
    Int() : v1(0), v2(0) {}
    Int(int v1, int v2) : v1(v1), v2(v2) {}

    Int& operator+=(int x) {
        ++x;
//         x += 123;
        v1 += p1[x];
        if (v1 >= mod1) v1 -= mod1;
        v2 += p2[x];
        if (v2 >= mod2) v2 -= mod2;
        return *this;
    }

    Int& operator-=(int x) {
        ++x;
//         x += 123;
        v1 -= p1[x];
        if (v1 < 0) v1 += mod1;
        v2 -= p2[x];
        if (v2 < 0) v2 += mod2;
        return *this;
    }

    Int& operator++() {
        v1 = (i64)v1 * base1 % mod1;
        v2 = (i64)v2 * base2 % mod2;
        return *this;
    }

    bool operator<(const Int& o) const {
        return std::tie(v1, v2) < std::tie(o.v1, o.v2);
    }

    bool operator!=(const Int& o) const {
        return v1 != o.v1 || v2 != o.v2;
    }

    operator bool() const {
        return v1 != 0 || v2 != 0;
    }
};

int n, m;
char s[maxn], t[maxn];

const int K = 26;

Int h1[K], h2[K];
pair<Int, int> t1[K], t2[K];
int rp[K];

bool match() {
//     int z1 = 0;
//     int z2 = 0;
    forn(i, K) {
        t1[i] = mp(h1[i], i);
//         if (!h1[i]) {
//             t1[i].fi = Int(--z1, 0);
//         }
        t2[i] = mp(h2[i], i);
//         if (!h2[i]) {
//             t2[i].fi = Int(--z2, 0);
//         }
    }
    sort(t1, t1+K);
    sort(t2, t2+K);

//     forn(j, K) cout << t1[j].fi.v1 << " " << t1[j].fi.v2 << endl; cout << endl;
//     forn(j, K) cout << t2[j].fi.v1 << " " << t1[j].fi.v2 << endl;
//     cout << "---------" << endl;

    forn(i, K) {
        if (t1[i].fi != t2[i].fi) {
            return false;
        }
        rp[t1[i].se] = t2[i].se;
    }
//     forn(i, K) cout << rp[i] << " "; cout << endl;
//     assert(z1 == z2);
    forn(i, K) if (h1[i] && h1[rp[i]]) {
        if (rp[rp[i]] != i) {
//             cout << "fail on " << i << endl;
            return false;
        }
    }
    return true;
}

void scan() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
}

void solve() {
    vi res;
    forn(i, m) {
        h1[s[i]-'a'] += i;
        h2[t[i]-'a'] += i;
    }

//     forn(j, K) cout << h1[j].v1 << " " << h1[j].v2 << endl; cout << endl;
//     forn(j, K) cout << h2[j].v1 << " " << h2[j].v2 << endl;
//     cout << "---------" << endl;

    forn(i, n-m+1) {
        if (match()) {
            res.pb(i);
        }
        forn(j, K) {
            ++h2[j];
        }
        if (i + m < n) {
            h1[s[i]-'a'] -= i;
            h1[s[i+m]-'a'] += i+m;
        } else {
            break;
        }
//         forn(j, K) cout << h1[j].v1 << " " << h1[j].v2 << endl; cout << endl;
//         forn(j, K) cout << h2[j].v1 << " " << h2[j].v2 << endl;
//         cout << "---------" << endl;
    }
    printf("%d\n", (int)res.size());
    for (auto c: res) {
        printf("%d ", c+1);
    }
    printf("\n");
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    genp();

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}