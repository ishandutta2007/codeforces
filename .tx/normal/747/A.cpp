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
    int aa = -1, ab = -1;
    int b = n;
    for (int a = 1; a <= n; a++) {
        while (1LL * a * b > n) {
            b--;
        }
        if (a > b) {
            break;
        }
        if (1LL * a * b == n) {
            aa = a;
            ab = b;
        }
    }
    
    cout << aa << " " << ab;

    return 0;
}