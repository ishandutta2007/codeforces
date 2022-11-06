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

    scid(s, x1, x2);
    scid(t1, t2);
    scid(p, d);
    
    if (x1 > x2) {
        x1 = s - x1;
        x2 = s - x2;
        d = -d;
        p = s - p;
    }
    
    int ans = (x2 - x1) * t2;
    
    int tt = 0;
    if (d == 1) {
        if (p > x1) {
            tt = (s - p + s + x2) * t1;
        } else {
            tt = (x2 - p) * t1;
        }
    } else {
        tt = (p + x2) * t1;
    }
    
    ans = min(ans, tt);
    cout << ans;
    
    

    return 0;
}