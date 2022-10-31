#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> ll round(T x) { return x < 0 ? x - 0.5 : x + 0.5; }
template<class T> void minimize(T & x, const T & y) {
    if (y < x) x = y;
}
template<class T> void maximize(T & x, const T & y) {
    if (x < y) x = y;
}
template<class T> T abs(T x) { return x < 0 ? -x : x; }

const ll LINF = (ll)1e18 + 5;
const int N = 200200;
const int K = 55;

int n, k, t[N];
ld DP[K][N];
ld S[N], SST[N], inverse[N];

void precalc() {
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + t[i];
        SST[i] = SST[i - 1] + ld(S[i]) / t[i];
        inverse[i] = inverse[i - 1] + ld(1) / t[i];
    }
}

ld brute() {
    fill(&DP[0][0], &DP[0][0] + sizeof(DP) / sizeof(DP[0][0]), LINF);

    DP[0][0] = 0;

    for (int cnt = 1; cnt <= k; cnt++) {
        for (int r = 1; r <= n; r++) {
            for (int l = 1; l <= r; l++) {
                minimize(DP[cnt][r], DP[cnt - 1][l - 1] + SST[r] - SST[l - 1] - S[l - 1] * (inverse[r] - inverse[l - 1]));
            }
        }
    }

    return DP[k][n];
}

struct line {
    ld k, b;
    line() {}
    line(ld k, ld b) : k(k), b(b) {}
    ld get(ld x) const {
        return k * x + b;
    }
};

ld getIntersection(const line & A, const line & B) {
    return (A.b - B.b) / (B.k - A.k);
}

bool isBad(const line & A, const line & B, const line & C) {
    return getIntersection(A, B) >= getIntersection(B, C);
}

struct ConvexHullTrick {
    vector<line> v;
    int ptr = 0;
    void addLine(line l) {
        while (v.size() >= 2 && isBad(v[(int)v.size() - 2], v.back(), l)) v.pop_back();
        v.push_back(l);
    }
    ld best(ld x) {
        while (ptr + 1 < (int)v.size() && v[ptr].get(x) >= v[ptr + 1].get(x)) ptr++;
        return v[ptr].get(x);
    }
};

ld solve() {
    fill(&DP[0][0], &DP[0][0] + sizeof(DP) / sizeof(DP[0][0]), LINF);

    DP[0][0] = 0;

    ConvexHullTrick cht;

    for (int cnt = 1; cnt <= k; cnt++) {
        cht.v.resize(0);
        cht.ptr = 0;
        for (int l = cnt; l <= n; l++) {
            ld kk = -S[l - 1];
            ld bb = DP[cnt - 1][l - 1] + S[l - 1] * inverse[l - 1] - SST[l - 1];
            cht.addLine(line(kk, bb));
        }
        for (int r = cnt; r <= n; r++) {
            ld x = inverse[r];
            DP[cnt][r] = cht.best(x) + SST[r];
        }
    }
    return DP[k][n];
}

void gen() {
    ofstream fout("input.txt");
    fout << 5000 <<  " " << 44 << endl;
    for (int i = 1; i <= 5000; i++) {
        fout << (rand() % 100000) + 1 << " ";
    }
    fout << endl;
    fout.close();
}

int main() {
#ifdef LOCAL
    gen();
    freopen("input.txt", "r", stdin);
#else
#endif

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    precalc();

    //ld brt = brute();
    ld slv = solve();

    //printf("%.20f\n", (double)brt);
    printf("%.20f\n", (double)slv);

    return 0;
}