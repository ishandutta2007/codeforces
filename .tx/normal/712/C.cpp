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

int a[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(x, y);

    a[0] = a[1] = a[2] = y;

    int ans = 0;
    while (a[0] < x || a[1] < x || a[2] < x) {
        sort(a, a + 3);
        a[0] = min(x, a[1] + a[2] - 1);
        ans++;
    }

    cout << ans;


    return 0;
}