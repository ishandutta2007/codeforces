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

lint a[222222];
lint b[222222];
lint c[222222];
lint d[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, k);
    scidl(x, s);
    
    for (int i = 1; i <= m; i++) {
        sci(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        sci(b[i]);
    }
    
    a[0] = x;
    ++m;

    for (int i = 1; i <= k; i++) {
        sci(c[i]);
    }
    for (int i = 1; i <= k; i++) {
        sci(d[i]);
    }
    
    ++k;
    
    lint ans = x * n;
    
    for (int i = 0; i < m; i++) {
        if (b[i] > s) {
            continue;
        }
        int j = upper_bound(d, d + k, s - b[i]) - d;
        --j;
        ans = min(ans, a[i] * (n - c[j]));
    }
    
    cout << ans;
    

    return 0;
}