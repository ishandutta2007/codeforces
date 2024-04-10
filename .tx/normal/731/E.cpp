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

lint a[222222];
lint d[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = x;
        if (i) {
            a[i] += a[i - 1];
        }
    }

    lint ans = a[n - 1];
    lint mx = ans;
    d[n - 1] = ans;
    for (int i = n - 2; i >= 1; i--) {
        mx = max(mx, a[i] - d[i + 1]);
        d[i] = mx;
    }

    cout << mx;

    return 0;
}