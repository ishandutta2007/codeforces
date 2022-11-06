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

    int x, h, m;
    scanf("%d\n%d:%d", &x, &h, &m);
    if (m >= 60) {
        m = 10 + m % 10;
    }
    if (x == 12) {
        if (h == 0) {
            h = 1;
        } else if (h > 12) {
            h = h % 10;
            if (h == 0) {
                h = 10;
            }
        }
    } else {
        if (h >= 24) {
            h %= 10;
        }
    }

    printf("%02d:%02d", h, m);

    return 0;
}