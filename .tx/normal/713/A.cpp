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

lint get_mask(lint x) {
    lint p10 = 1;
    lint res = 0;
    while (x > 0) {
        res += (x % 2) * p10;
        x /= 10;
        p10 *= 10;
    }
    return res;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    unordered_map<lint, int> cnt(1e6);
    scid(n);
    for (int i = 0; i < n; i++) {
        scids(s);
        scidl(x);
        if (s == "?") {
            cout << cnt[x] << "\n";
        } else if (s == "+") {
            cnt[get_mask(x)]++;
        } else {
            cnt[get_mask(x)]--;
        }
    }

    return 0;
}