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

int l[111111];
int r[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    int sl = 0;
    int sr = 0;
    for (int i = 0; i < n; i++) {
        sci(l[i], r[i]);
        sl += l[i];
        sr += r[i];
    }

    int ans = abs(sl - sr);
    int ai = -1;
    for (int i = 0; i < n; i++) {
        int tsl = sl - l[i] + r[i];
        int tsr = sr - r[i] + l[i];
        if (abs(tsl - tsr) > ans) {
            ans = abs(tsl - tsr);
            ai = i;
        }
    }

    cout << ai + 1;

    return 0;
}