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

    scidl(n, k);
    lint len = (1LL << n) - 1;
    --k;
    while (true) {
        lint md = (1LL << (n - 1)) - 1;
        if (k == md) {
            cout << n;
            return 0;
        } 
        if (k > md) {
            k -= md + 1;
        }
        --n;
    }

    return 0;
}