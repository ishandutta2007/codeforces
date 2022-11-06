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
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

lint a[111][111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scidl(n, m, k, x, y);
    --x; --y;
    
    if (n == 1) {
        lint t = k / m;
        k %= m;
        for (int i = 0; i < m; i++) {
            a[0][i] = t;
        }
    } else {
        lint t = k / (2 * (n - 1) * m);
        k %= (2 * (n - 1) * m);
        for (int i = 0; i < m; i++) {
            a[0][i] = a[n - 1][i] = t;
            for (int j = 1; j + 1 < n; j++) {
                a[j][i] = 2 * t;
            }
        }
    }
    
    int i = 0, j = 0;
    int dir = 1;
    while (k > 0) {
        k--;
        a[i][j]++;
        j++;
        if (j == m) {
            j = 0;
            if (n != 1) {
                i += dir;
                if (i == 0 || i == n - 1) {
                    dir = -dir;
                }
            }
        }
    }
    
    lint mx = -2e18, mn = 2e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
//            cout << a[i][j] << " ";
            mx = max(mx, a[i][j]);
            mn = min(mn, a[i][j]);
        }
//        cout << endl;
    }
    
    cout << mx << " " << mn << " " << a[x][y];

    return 0;
}