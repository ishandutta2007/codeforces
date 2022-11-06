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
    
    scid(n, m, k);
    --k;
    int r = k / (2 * m);
    k %= 2 * m;
    int d = k / 2;
    k -= 2 * d;
    cout << r + 1 << " " << d + 1 << " " << "LR"[k];

    return 0;
}