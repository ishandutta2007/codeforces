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

    scid(n, k, a, b);
    string ans = "";
    int lc = 0;
    if (a > b) {
        lc = 1;
    }
    int cn = 0;
    for (int i = 0; i < n; i++) {
        if (cn == k) {
            if (lc == 0) {
                if (b == 0) {
                    cout << "NO";
                    return 0;
                }
                --b;
                ans += 'B';
                lc = 1;
            } else {
                if (a == 0) {
                    cout << "NO";
                    return 0;
                }
                --a;
                ans += 'G';
                lc = 0;
            }
            cn = 1;
        } else if (a > b) {
            --a;
            ans += 'G';
            if (lc == 0) {
                cn++;
            } else {
                cn = 1;
                lc = 0;
            }
        } else {
            --b;
            ans += 'B';
            if (lc == 1) {
                cn++;
            } else {
                cn = 1;
                lc = 1;
            }
        }
    }
    
    cout << ans;

    return 0;
}