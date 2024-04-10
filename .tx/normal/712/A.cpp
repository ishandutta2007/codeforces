#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

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

int a[111111];
int b[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }

    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        // a[i] = -a[i + 1] + b[i] => b[i] = a[i] + a[i + 1]
        b[i] = a[i] + a[i + 1];
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}