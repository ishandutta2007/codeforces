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

string a[4];

bool same(int x, int y, int dx, int dy) {
    for (int i = 1; i < 3; i++) {
        if (x + dx * i >= 4 || y + dy * i >= 4 || a[x + dx * i][y + dy * i] != a[x][y]) {
            return false;
        }
    }
    return true;
}

bool xwin() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] != 'x') {
                continue;
            }
            if (same(i, j, 0, 1) || same(i, j, 1, 0) || same(i, j, 1, 1) || same(i, j, 1, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i < 4; i++) {
        sci(a[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == '.') {
                a[i][j] = 'x';
                if (xwin()) {
                    cout << "YES";
                    return 0;
                }
                a[i][j] = '.';
            }
        }
    }
    
    cout << "NO";

    return 0;
}