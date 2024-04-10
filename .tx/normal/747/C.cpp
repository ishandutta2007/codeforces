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

int ft[111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, q);
    while (q-- > 0) {
        scid(t, k, d);
        int hf = 0;
        for (int i = 0; hf < k && i < n; i++) {
            if (ft[i] <= t) {
                hf++;
            }
        }
        if (hf < k) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        hf = 0;
        for (int i = 0; hf < k && i < n; i++) {
            if (ft[i] <= t) {
                ft[i] = t + d;
                hf++;
                ans += i + 1;
            }
        }
        cout << ans << "\n";
    }
    

    return 0;
}