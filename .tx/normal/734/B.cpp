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

    scid(k2, k3, k5, k6);
    int ans = 0;
    while (k2 > 0 && k5 > 0 && k6 > 0) {
        ans += 256;
        --k2;
        --k5;
        --k6;
    }
    
    while (k2 > 0 && k3 > 0) {
        ans += 32;
        --k2;
        --k3;
    }
    
    cout << ans;

    return 0;
}