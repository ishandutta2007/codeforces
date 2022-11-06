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

const int MOD = 1e9 + 7;

lint mpow(lint a, lint p) {
    lint res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = (res * a) % MOD;
        }
        a = a * a % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(k);

    lint p2 = 2;

    bool n1 = false;
    bool odd = true;

    for (int i = 0; i < k; i++) {
        scidl(x);
        if (x != 1) {
            n1 = true;
        }
        if (x % 2 == 0) {
            odd = false;
        }
        p2 = mpow(p2, x);
    }

    if (!n1) {
        cout << "0/1";
        return 0;
    }

    p2 = p2 * mpow(2, MOD - 2) % MOD;

    lint t = (p2 + 1) * mpow(3, MOD - 2) % MOD;
    if (odd) {
        t = (p2 - 1) * mpow(3, MOD - 2) % MOD;
        t = (t + MOD) % MOD;
    }

    cout << t << "/" << p2;

    return 0;
}