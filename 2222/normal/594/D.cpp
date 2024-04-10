#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

const int mod = 1000000007;

inline int mul(int x, int y) { return (ll)x * y % mod; }

int n, m;
int a[200222];
pii q[200222];
int d[1000111];
int ans[200222];

int F[1 << 19];

void segmul(int x, int y, int v) {
    x += (1 << 18);
    y += (1 << 18);
    for (; x <= y; x = (x + 1) / 2, y = (y - 1) / 2) {
        if (x & 1) F[x] = mul(F[x], v);
        if (~y & 1) F[y] = mul(F[y], v);
    }
}

int get(int x) { 
    int res = 1;
    for (x += (1 << 18); x; x /= 2)
        res = mul(res, F[x]);
    return res;
}

int main() {
    for (int p = 2; p * p < 1000111; ++p)
        if (d[p] == 0) {
            for (int x = p * p; x < 1000111; x += p)
                d[x] = p;
        }
    fill(F, F + (1 << 19), 1);
    scanf("%d", &n);
    REP (i, n) {
        scanf("%d", a + i);
    }
    scanf("%d", &m);
    vector<pii> events;
    REP (i, m) {
        scanf("%d%d", &q[i].X, &q[i].Y);
        --q[i].X;
        --q[i].Y;
        events.emplace_back(q[i].Y, i);
    }
    sort(all(events));
    int j = 0;
    unordered_map<int, int> prev;
    REP (i, n) {
        vector<pii> f;
        int x = a[i];
        for (; int y = d[x]; ) {
            int k = 0;
            do { x /= y; ++k; } while (x % y == 0);
            f.emplace_back(y, k);
        }
        if (x > 1) f.emplace_back(x, 1);
        // cout << a[i];
        // for (auto p : f) cout << " (" << p.X << ' ' << p.Y << ")";
        // cout << endl;
        for (auto &p : f) {
            auto t = prev.find(p.X);
            int q = 1;
            REP (k, p.Y) q *= p.X;
            int phi = q - q / p.X;
            //cout << p.X << ' ' << q << ' ' << phi << endl;
            if (t == prev.end()) {
                segmul(0, i, phi);
            } else {
                segmul(0, t->Y, q);
                segmul(t->Y + 1, i, phi);
            }
            prev[p.X] = i;
        }
        for (; j < sz(events) && events[j].X == i; ++j) {
            auto &e = events[j];
            ans[e.Y] = get(q[e.Y].X);
        }
    }
    REP (i, m) {
        printf("%d\n", ans[i]);
    }
    return 0;
}