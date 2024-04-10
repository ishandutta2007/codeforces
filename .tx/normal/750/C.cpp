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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    scid(n);
    lint l = -1e9;
    lint r = 1e9;
    for (int i = 0; i < n; i++) {
        scid(x, y);
        if (y == 1) {
            if (r < 1900) {
                cout << "Impossible";
                return 0;
            }
            l = max(l, 1900ll);
        } else {
            if (l >= 1900) {
                cout << "Impossible";
                return 0;
            }
            r = min(r, 1899ll);
        }
        if (l != -1e9) {
            l += x;
        }
        if (r != 1e9) {
            r += x;
        }
    }
    
    if (r == 1e9) {
        cout << "Infinity";
    } else {
        cout << r;
    }

    return 0;
}