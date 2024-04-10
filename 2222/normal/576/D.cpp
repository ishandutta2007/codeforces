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

const int N = 166;

int n;

using vec = bitset<N>;

struct mat {
    vector<vec> a;
    mat() : a(n) {}
    vec& operator[] (int i) { return a[i]; }
};

mat operator * (mat& a, mat& b) {
    mat c;
    REP (i, n) REP (k, n) {
        if (a[i][k])
            c[i] |= b[k];
    }
    return c;
}

vec operator * (vec &a, mat &b) {
    vec c;
    REP (i, n) if (a[i]) c |= b[i];
    return c;
}

int main() {
    int m;
    cin >> n >> m;
    vector<pair<int, pii>> edges;
    REP (k, m) {
        int x, y, d;
        cin >> x >> y >> d;
        edges.pb({d, {x -  1, y - 1}});
    }
    sort(all(edges));
    edges.pb({-1u/2, {0, 0}});
    mat a, b;
    vec p;
    p[0] = 1;
    int tm = 0;
    REP (i, n) b[i][i] = true;
    REP (k, sz(edges)) {
        int d = edges[k].X;
        int x = edges[k].Y.X;
        int y = edges[k].Y.Y;
        vector<mat> pwa, pwb;
        pwa.pb(a);
        pwb.pb(b);
        for (int l = 1; (1ll << l) <= d - tm; ++l) {
            pwa.pb(pwa[l - 1] * pwa[l - 1]);
            pwb.pb(pwb[l - 1] * pwb[l - 1]);
        }
        mat A, B;
        REP (i, n) A[i][i] = B[i][i] = true;
        REP (k, sz(pwa)) {
            if ((d - tm) & 1 << k) {
                A = A * pwa[k];
                B = B * pwb[k];
            }
        }
        vec Q = p * B;
        if (!Q[n - 1]) {
            p = p * A;
            a[x][y] = true;
            b[x][y] = true;
            tm = d;
            continue;
        } 
        for (int k = sz(pwb); k --> 0; ) {
            if ((1 << k) > d - tm) 
                continue;
            Q = p * pwb[k];
            if (!Q[n - 1]) {
                p = p * pwa[k];
                tm += 1 << k;
            }
        }
        cout << tm + 1 << endl;
        return 0;
    }
    puts("Impossible");
    return 0;
}