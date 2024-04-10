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
    scids(s);
    int ka = 0, kd = 0;
    for (char c : s) {
        if (c == 'A') {
            ka++;
        } else {
            kd++;
        }
    }

    if (ka > kd) {
        cout << "Anton";
    } else if (ka < kd) {
        cout << "Danik";
    } else {
        cout << "Friendship";
    }

    return 0;
}