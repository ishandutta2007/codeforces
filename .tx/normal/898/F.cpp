#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
static const int PRS = 31;
static const int NN = 1000111;
using lint = long long;

int prs[50] = {2100000011,2100000017,2100000053,2100000101,2100000127,2100000151,2100000169,2100000173,2100000209,2100000263,2100000277,2100000283,2100000307,2100000311,2100000317,2100000319,2100000367,2100000407,2100000449,2100000493,2100000523,2100000541,2100000547,2100000569,2100000587,2100000619,2100000647,2100000653,2100000659,2100000677,2100000691,2100000737,2100000811,2100000829,2100000841,2100000887,2100000893,2100000907,2100000911,2100000919,2100000943,2100000949,2100000961,2100000997,2100001021,2100001037,2100001069,2100001097,2100001103,2100001117};
int p10[PRS][NN];
int h[PRS][NN];
int n;
string s;

void add(int& a, int b, int im) {
    a = (0LL + a + b) % prs[im];
    if (a < 0) {
        a += prs[im];
    }
}

int get(int l, int r, int im) {
    int res = h[im][r];
    if (l > 0) {
        add(res, -1LL * h[im][l - 1] * p10[im][r - l + 1] % prs[im], im);
    }
    return res;
}

void check(int i, int j) {
    if (i >= j || j >= n - 1) {
        return;
    }
    rep(im, 0, PRS) {
        int x = get(0, i, im);
        int y = get(i + 1, j, im);
        int z = get(j + 1, n - 1, im);
        add(x, y, im);
        if (x != z) {
            return;
        }
    }
    rep(is, 0, i + 1) {
        cout << s[is];
    }
    cout << "+";
    rep(is, i + 1, j + 1) {
        cout << s[is];
    }
    cout << "=";
    rep(is, j + 1, n) {
        cout << s[is];
    }
    cout.flush();
    exit(0);
}

void solve(istream& cin, ostream& cout) {
    rep(i, 0, PRS) {
        p10[i][0] = 1;
        rep(j, 1, NN) {
            p10[i][j] = 1LL * p10[i][j - 1] * 10 % prs[i];
        }
    }
    cin >> s;
    n = s.size();

    rep(im, 0, PRS) {
        rep(i, 0, n) {
            h[im][i] = s[i] - '0';
            if (i) {
                add(h[im][i], 1LL * h[im][i - 1] * 10 % prs[im], im);
            }
        }
    }

    int l2 = n / 2;
    rep(i, 0, n) {
        int l1 = i + 1;
        int l3 = n - l1 - l2;
        while (l3 > max(l1, l2) + 1) {
            l3--;
            l2++;
        }
        while (l3 < max(l1, l2)) {
            l3++;
            l2--;
        }
        if (l3 <= 0 || l2 <= 0) {
            continue;
        }
        int j = l1 + l2 - 1;
        if (s[0] == '0' && l1 > 1) {
            continue;
        }
        if (s[l1] == '0' && l2 > 1) {
            continue;
        }
        if (s[l1 + l2] == '0' && l3 > 1) {
        } else {
            check(i, j);
        }
        if (s[l1 + l2 - 1] == '0' && l3 + 1 > 1) {
        } else {
            check(i, j - 1);
        }

        if (s[l1 + l2 + 1] == '0' && l3 - 1 > 1) {
        } else {
            check(i, j + 1);
        }
    }
    cout << ":(";
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}