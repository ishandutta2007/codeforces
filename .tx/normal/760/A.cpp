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

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(m, d);
    --d;
    int ans = 1;
    for (int i = 1; i < md[m]; i++) {
        d++;
        if (d == 7) {
            d = 0;
            ans++;
        }
    }
    cout << ans;

    return 0;
}