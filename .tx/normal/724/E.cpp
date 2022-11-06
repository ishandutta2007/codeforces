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

lint d[2][11111];
int p[11111];
int s[11111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, c);
    for (int i = 0; i < n; i++) {
        sci(p[i]);
    }

    for (int i = 0; i < n; i++) {
        sci(s[i]);
    }

    int tt = (n - 1) & 1;
    d[tt][0] = p[n - 1];
    d[tt][1] = s[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        int cur = i & 1;
        int prev = 1 - cur;
        d[cur][0] = d[prev][0] + p[i];
        d[cur][n - i] = d[prev][n - i - 1] + s[i];
        for (int j = 1; j < n - i; j++) {
            d[cur][j] = min(d[prev][j] + p[i], d[prev][j - 1] + s[i] + 1LL * (n - i - j) * c);
        }
    }

    lint ans = 1e18;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, d[0][i]);
    }

    cout << ans;

    return 0;
}