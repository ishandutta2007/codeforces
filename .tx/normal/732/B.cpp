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

int a[555];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, k);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int t = max(0, k - a[i] - a[i - 1]);
        a[i] += t;
        ans += t;
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}