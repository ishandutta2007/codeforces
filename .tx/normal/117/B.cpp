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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scidl(a, b, mod);
    lint e9 = 1e9;
    if (a <= mod) {
        for (lint i = 1; i <= a; i++) {
            lint x = i * e9 % mod;
            if (x != 0 && x + b < mod) {
                printf("1 %09lld", i);
                return 0;
            }
        }
        printf("2");
        return 0;
    }

    if (b >= mod) {
        printf("2");
        return 0;
    }

    for (lint i = 1; i <= mod; i++) {
        lint x = i * e9 % mod;
        if (x != 0 && x + b < mod) {
            printf("1 %09lld", i);
            return 0;
        }
    }

    printf("2");

    return 0;
}