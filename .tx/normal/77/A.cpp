#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int p[7];
int cs[7][7];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    map<string, int> bn;
    bn["Anka"] = 0;
    bn["Chapay"] = 1;
    bn["Cleo"] = 2;
    bn["Troll"] = 3;
    bn["Dracul"] = 4;
    bn["Snowy"] = 5;
    bn["Hexadecimal"] = 6;

    for (int i = 0; i < n; i++) {
        scids(p, t, q);
        int x = bn[p];
        int y = bn[q];
        cs[x][y]++;
    }

    scid(a, b, c);

    for (int i = 0; i < 7; ++i) {
        p[i] = i;
    }

    int ad = -1;
    int as = -1;

    do {
        for (int i1 = 1; i1 < 7; i1++) {
            for (int i2 = 1; i1 + i2 < 7; i2++) {
                int i3 = 7 - i1 - i2;
                int x1 = a / i1;
                int x2 = b / i2;
                int x3 = c / i3;
                int mx = max(max(x1, x2), x3);
                int mn = min(min(x1, x2), x3);
                int d = mx - mn;
                if (d == 0) {
                    d += 1;
                    d--;
                }

                int s = 0;
                for (int i = 0; i < i1; i++) {
                    for (int j = 0; j < i1; j++) {
                        s += cs[p[i]][p[j]];
                    }
                }

                for (int i = 0; i < i2; i++) {
                    for (int j = 0; j < i2; j++) {
                        s += cs[p[i + i1]][p[j + i1]];
                    }
                }

                for (int i = 0; i < i3; i++) {
                    for (int j = 0; j < i3; j++) {
                        s += cs[p[i + i1 + i2]][p[j + i1 + i2]];
                    }
                }

                if (ad == -1 || d < ad) {
                    ad = d;
                    as = -1;
                }

                if (d == ad) {
                    as = max(as, s);
                }
            }
        }
    } while (next_permutation(p, p + 7));


    cout << ad << " " << as;

    return 0;
}