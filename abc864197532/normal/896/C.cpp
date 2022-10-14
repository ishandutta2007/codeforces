#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 3e6;

struct interval {
    int l, r;
    long long v;
    interval (int _l, int _r, long long _v) : l(_l), r(_r), v(_v) {}
};

struct cmp {
    bool operator () (const interval &a, const interval& b) {
        return a.l < b.l;
    }
};

int seed;

int rnd() {
    int tmp = seed;
    seed = (7ll * seed + 13) % mod;
    return tmp;
}

lli modpow(lli a, int b, int mod) {
    a %= mod;
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

set <interval, cmp> s;

vector <interval> split(int l, int r) {
    vector <interval> del, ans, re;
    auto it = s.lower_bound(interval(l, -1, 0));
    if (it != s.begin() && (it == s.end() || l < it->l)) {
        --it;
        del.pb(*it);
        if (r < it->r) {
            re.pb(interval(it->l, l, it->v));
            ans.pb(interval(l, r, it->v));
            re.pb(interval(r, it->r, it->v));
        } else {
            re.pb(interval(it->l, l, it->v));
            ans.pb(interval(l, it->r, it->v));
        }
        ++it;
    }
    for (; it != s.end() && it->r <= r; ++it) {
        ans.pb(*it);
        del.pb(*it);
    }
    if (it != s.end() && it->l < r) {
        del.pb(*it);
        ans.pb(interval(it->l, r, it->v));
        re.pb(interval(r, it->r, it->v));
    }
    for (interval &i : del) s.erase(i);
    for (interval &i : re) s.insert(i);
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, C;
    cin >> n >> q >> seed >> C;
    for (int i = 0; i < n; ++i) {
        s.insert(interval(i, i + 1, rnd() % C + 1));
    }
    while (q--) {
        int op = rnd() % 4, l = rnd() % n, r = rnd() % n, x, y;
        if (l > r) swap(l, r);
        r++;
        vector <interval> cur = split(l, r);
        if (op == 0) {
            x = rnd() % C + 1;
            for (interval &i : cur) {
                s.insert(interval(i.l, i.r, i.v + x));
            }
        } else if (op == 1) {
            x = rnd() % C + 1;
            s.insert(interval(l, r, x));
        } else if (op == 2) {
            x = rnd() % (r - l);
            vector <pair <long long, int>> now;
            for (interval &i : cur) {
                s.insert(i);
                now.eb(i.v, i.r - i.l);
            }
            sort(all(now));
            for (pair <long long, int> &i : now) {
                if (0 <= x && x < i.Y) {
                    cout << i.X << '\n';
                }
                x -= i.Y;
            }
        } else {
            x = rnd() % C + 1;
            y = rnd() % C + 1;
            long long ans = 0;
            for (interval &i : cur) {
                s.insert(i);
                (ans += modpow(i.v, x, y) * (i.r - i.l)) %= y;
            }
            cout << ans << '\n';
        }
    }
}