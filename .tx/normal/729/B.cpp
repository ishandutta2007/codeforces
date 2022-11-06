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

int a[1111][1111];
int su[1111][1111];
int sl[1111][1111];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sci(a[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sl[i][j + 1] = a[i][j] + sl[i][j];
            su[i + 1][j] = a[i][j] + su[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                continue;
            }
            
            if (sl[i][j]) {
                ans++;
            }
            if (su[i][j]) {
                ans++;
            }
            if (sl[i][m] - sl[i][j]) {
                ans++;
            }
            if (su[n][j] - su[i][j]) {
                ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}