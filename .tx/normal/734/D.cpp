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

typedef long long lint;

bool has[9];
int opt[9];
char who[9];

//hello

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scid(x0, y0);

    for (int i = 0; i < n; i++) {
        scids(s);
        scid(x, y);
        char c = s[0];
        if (x == x0) {
            if (y > y0) {
                if (!has[0] || y < opt[0]) {
                    has[0] = true;
                    opt[0] = y;
                    who[0] = c;
                }
            } else {
                if (!has[1] || y > opt[1]) {
                    has[1] = true;
                    opt[1] = y;
                    who[1] = c;
                }
            }
        }
        if (y == y0) {
            if (x > x0) {
                if (!has[2] || x < opt[2]) {
                    opt[2] = x;
                    has[2] = true;
                    who[2] = c;
                }
            } else {
                if (!has[3] || x > opt[3]) {
                    opt[3] = x;
                    has[3] = true;
                    who[3] = c;
                }
            }
        }
        if (x + y == x0 + y0) {
            if (x > x0) {
                if (!has[5] || x < opt[5]) {
                    has[5] = true;
                    opt[5] = x;
                    who[5] = c;
                }
            } else {
                if (!has[6] || x > opt[6]) {
                    has[6] = true;
                    opt[6] = x;
                    who[6] = c;
                }
            }
        }
        if (x - y == x0 - y0) {
            if (x > x0) {
                if (!has[7] || x < opt[7]) {
                    has[7] = true;
                    opt[7] = x;
                    who[7] = c;
                }
            } else {
                if (!has[8] || x > opt[8]) {
                    has[8] = true;
                    opt[8] = x;
                    who[8] = c;
                }
            }
        }
    }

    for (int i = 0; i <= 3; i++) {
        if (has[i] && who[i] != 'B') {
            cout << "YES";
            return 0;
        }
    }

    for (int i = 5; i <= 8; i++) {
        if (has[i] && who[i] != 'R') {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}