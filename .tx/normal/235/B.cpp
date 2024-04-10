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
    double ans = 0;
    scidd(y);
    ans += y;
    double d = 0;
    for (int i = 1; i < n; i++) {
        scidd(x);
        d = (d + y) * x;
        ans += x + 2 * d;
        y = x;
    }
    
    printf("%.11lf", ans);

    return 0;
}