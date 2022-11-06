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

int a[111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    if (a[n - 1] == 0) {
        cout << "UP";
    } else if (a[n - 1] == 15) {
        cout << "DOWN";
    } else if (n == 1) {
        cout << -1;
    } else if (a[n - 1] > a[n - 2]) {
        cout << "UP";
    } else {
        cout << "DOWN";
    }


    return 0;
}