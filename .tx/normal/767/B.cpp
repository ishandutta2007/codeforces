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

template <typename T>
using heap = priority_queue<T, std::vector<T>, std::greater<T>>;

typedef long long lint;

lint ts[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scidl(s, f, t);
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(ts[i]);
    }
    if (n == 0 || ts[0] > s) {
        cout << s;
        return 0;
    }
    lint ans = ts[0] - 1;
    lint wt = s - ans;
    
    int i = 0;
    lint ft = s;
    while (i < n) {
        int k = 0;
        while (i + k < n && ts[i] == ts[i + k]) {
            k++;
        }
        if (ft <= ts[i]) {
            ft = ts[i] + k * t;
        } else {
            ft += k * t;
        }
        if (ft + t > f) {
            i += k;
            continue;
        }
        lint at;
        if (i + k == n) {
            at = ft;
        } else {
            at = ts[i + k] - 1;
        }
        lint x = ft - at;
        if (x < 0) {
            at = ft;
            x = 0;
        }
        if (x < wt) {
            wt = x;
            ans = at;
        }
        i += k;
    }
    
    cout << ans;
    
    return 0;
}