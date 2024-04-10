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

bool isd(char c) {
    return c >= '0' && c <= '9';
}

bool isc(char c) {
    return c >= 'a' && c <= 'z';
}

bool iss(char c) {
    return c == '#' || c == '*' || c == '&';
}

string a[55];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
        
    scid(n, m);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    
    int ans = 1e9;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                
                int c1 = -1;
                for (int t = 0; t < m; t++) {
                    if (isd(a[i][t]) || isd(a[i][(m - t) % m])) {
                        c1 = t;
                        break;
                    }
                }

                int c2 = -1;
                for (int t = 0; t < m; t++) {
                    if (isc(a[j][t]) || isc(a[j][(m - t) % m])) {
                        c2 = t;
                        break;
                    }
                }

                int c3 = -1;
                for (int t = 0; t < m; t++) {
                    if (iss(a[k][t]) || iss(a[k][(m - t) % m])) {
                        c3 = t;
                        break;
                    }
                }
                
                if (c1 == -1 || c2 == -1 || c3 == -1) {
                    continue;
                }
                ans = min(ans, c1 + c2 + c3);
            }
        }
    }
    
    cout << ans;
    

    return 0;
}