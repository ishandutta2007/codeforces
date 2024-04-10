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

int a[5555];
int b[5555];

lint d[2][5555];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        b[i] = a[i];
    }

    sort(b, b + n);


    for (int i = 1; i <= n; i++) {
        lint tt = 1e18;
        int cur = i & 1;
        int prev = 1 - cur;
        fill(d[cur], d[cur] + n, 0);

        for (int j = 0; j < n; j++) {
            tt = min(tt, d[prev][j]);
            d[cur][j] = tt + abs(a[i - 1] - b[j]);
        }
    }

//    cout << "b:" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << b[i] << " ";
//    }
//    cout << endl;
//
//    cout << "d:" << endl;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << d[i][j] << " ";
//        }
//        cout << endl;
//    }

    lint ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, d[n & 1][i]);
    }

    cout << ans;


    return 0;
}