#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int x[MAXN], fen[2][2][MAXN], n;

void fenAdd(int t0, int t1, int x, int add) {
    for(; x < n; x |= x + 1)
        fen[t0][t1][x] += add;
}

int fenGet(int t0, int t1, int x) {
    int res = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
        res += fen[t0][t1][x];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    for(int i = 0; i < q; i++) {
        int qt;
        cin >> qt;
        if(qt == 1) {
            int d, add;
            cin >> d >> add;
            d--;
            if(x[d] < b) {
                if(x[d] + add >= b) {
                    fenAdd(0, 0, d, -x[d]);
                    fenAdd(0, 1, d, 1);
                    if(x[d] + add < a)
                        fenAdd(1, 0, d, add);
                    else {
                        fenAdd(1, 0, d, -x[d]);
                        fenAdd(1, 1, d, 1);
                    }
                }
                else {
                    fenAdd(0, 0, d, add);
                    fenAdd(1, 0, d, add);
                }
            }
            else if(x[d] < a) {
                if(x[d] + add >= a) {
                    fenAdd(1, 0, d, -x[d]);
                    fenAdd(1, 1, d, 1);
                }
                else
                    fenAdd(1, 0, d, add);
            }
            x[d] += add;
        }
        else {
            int p;
            cin >> p;
            p--;
            int ans = (p? fenGet(0, 0, p - 1) + fenGet(0, 1, p - 1) * b : 0) +
                fenGet(1, 0, n - 1) - fenGet(1, 0, p + k - 1) +
                (fenGet(1, 1, n - 1) - fenGet(1, 1, p + k - 1)) * a;
            cout << ans << '\n';
        }
    }
    return 0;
}