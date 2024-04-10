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

int a[222222];

int h[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, s);
    --s;
    int kz = 0;
    for (int i = 1; i < n; i++) {
        h[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (i != s && a[i] == 0) {
            kz++;
        }
        if (i != s) {
            h[a[i]] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        h[i] += h[i - 1];
    }

    int ans = 0;
    if (a[s] != 0) {
        ans++;
        a[s] = 0;
    }

    sort(a, a + n);
    int rr = n - 1;
    int ca = n - 1;
    for (int i = n - 1; i > 0; i--) {
        while (rr >= 0 && a[rr] > i) {
            rr--;
        }
        int cp = h[i];
        int cmore = n - 1 - rr;
        int tt = max(0, cp - cmore - kz);
        ca = min(ca, cmore + kz + tt);
    }

    cout << ans + ca;



    return 0;
}