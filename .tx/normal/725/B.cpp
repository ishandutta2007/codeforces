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

    lint x = 0;
    char c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    --x;

    lint ans = 0;
    ans += (6 * 2 + 4) * (x / 4);
    x %= 4;
    if (x % 2 == 1) {
        ans += 6 + 1;
    }

    int hw[256];
    hw['f'] = 1;
    hw['e'] = 2;
    hw['d'] = 3;
    hw['a'] = 4;
    hw['b'] = 5;
    hw['c'] = 6;
    ans += hw[c];

    cout << ans;

    return 0;
}