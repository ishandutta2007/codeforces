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
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int d[11][22][22];
tuple<int, int, int> p[11][22][22];
int h[11];


int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, a, b);
    for (int i = 0; i < n; i++) {
        sci(h[i]);
        h[i]++;
    }

    int ans = 0;
    int b1 = (h[0] + b - 1) / b;
    ans += b1;
    h[0] = 0;
    h[1] = max(0, h[1] - b1 * a);
    h[2] = max(0, h[2] - b1 * b);

    int b2 = (h[n - 1] + b - 1) / b;
    ans += b2;
    h[n - 1] = 0;
    h[n - 2] = max(0, h[n - 2] - b2 * a);
    h[n - 3] = max(0, h[n - 3] - b2 * b);

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 22; j++) {
            for (int k = 0; k < 22; ++k) {
                d[i][j][k] = 1e9;
                p[i][j][k] = make_tuple(-1, -1, -1);
            }
        }
    }

    d[0][0][h[0]] = 0;
    for (int i = 0; i < n; i++) {
        for (int wa = 0; wa < 22; wa++) {
            for (int j = 0; j <= h[i]; j++) {
                for (int ca = 0; ca < 22; ca++) {
                    int r = max(0, j - ca * a);
                    int cb = (r + b - 1) / b;
                    int nh = max(0, h[i + 1] - cb * a - ca * b - wa * b);
//                    d[i + 1][ca][nh] = min(d[i + 1][ca][nh], d[i][wa][j] + ca + cb);
                    if (d[i + 1][cb][nh] > d[i][wa][j] + ca + cb) {
                        d[i + 1][cb][nh] = d[i][wa][j] + ca + cb;
                        p[i + 1][cb][nh] = make_tuple(wa, ca, j);
                    }
                }
            }
        }
    }

//    for (int i = 0; i <= 3; i++) {
//        for (int j = 0; j <= 2; j++) {
//            if (d[i][j] == 1e9) {
//                cout << '*';
//            } else {
//                cout << d[i][j];
//            }
//            cout << " ";
//        }
//        cout << "\n";
//    }

    cout << ans + d[n][0][0] << "\n";
    int x = 0;
    int y = 0;
    int i = n;
    while (get<0>(p[i][x][y]) != -1) {
        int wa, ca, j;
        tie(wa, ca, j) = p[i][x][y];
        for (int t = 0; t < wa + ca; t++) {
            cout << i << " ";
        }

        x = wa;
        y = j;
        i--;
    }

    for (int i = 0; i < b1; i++) {
        cout << 2 << " ";
    }

    for (int i = 0; i < b2; i++) {
        cout << n - 1 << " ";
    }

    return 0;
}