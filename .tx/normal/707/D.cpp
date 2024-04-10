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

int wv[100001][1000];

char vs[100000][1000];
int c1[100000];
int aans[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    scid(n, m, q);
    const size_t tfm = sizeof(char) * m;
    const size_t tfn = sizeof(int) * n;
    int vc = 1;
    int ans = 0;
    for (int cq = 1; cq <= q; cq++) {
        scid(tp);
        memcpy(wv[cq], wv[cq - 1], tfn);
        if (tp == 1 || tp == 2) {
            scid(x, y);
            --x; --y;
            memcpy(vs[vc], vs[wv[cq - 1][x]], tfm);
            int oy = vs[vc][y];
            vs[vc][y] = tp == 1 ? 1 : 0;
            wv[cq][x] = vc;
            c1[vc] = c1[wv[cq - 1][x]] + vs[vc][y] - oy;
            ans = ans - c1[wv[cq - 1][x]] + c1[vc];
            vc++;
        } else if (tp == 3) {
            scid(x);
            --x;
            for (int i = 0; i < m; i++) {
                vs[vc][i] = 1 - vs[wv[cq - 1][x]][i];
            }
            wv[cq][x] = vc;
            c1[vc] = m - c1[wv[cq - 1][x]];
            ans = ans - c1[wv[cq - 1][x]] + c1[vc];
            vc++;
        } else { // tp == 4
            scid(k);
            memcpy(wv[cq], wv[k], tfn);
            ans = aans[k];
        }

        aans[cq] = ans;
        cout << ans << "\n";
    }

    return 0;
}