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

bool ban[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scids(s);
    int cd = 0;
    int cr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            cd++;
        } else {
            cr++;
        }
    }
    int b = 0;
    while (cd != 0 && cr != 0) {
        for (int i = 0; i < n; i++) {
            if (ban[i]) {
                continue;
            }
            if (s[i] == 'D') {
                if (b >= 0) {
                    b++;
                } else {
                    ban[i] = true;
                    cd--;
                    b++;
                }
            } else {
                if (b <= 0) {
                    b--;
                } else {
                    ban[i] = true;
                    cr--;
                    b--;
                }
            }
        }
    }
    
    if (cd > 0) {
        cout << "D";
    } else {
        cout << "R";
    }

    return 0;
}