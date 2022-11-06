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

string a[555];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    int u = 1e9, d = -1e9, l = 1e9, r = -1e9;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                u = min(u, i);
                d = max(d, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }
    
    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            if (a[i][j] != 'X') {
                cout << "NO";
                return 0;
            }
        }
    }
    
    cout << "YES";
    

    return 0;
}