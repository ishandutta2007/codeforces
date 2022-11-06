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

    scid(n);
    scids(s);
    
    int ch = 0;
    for (char c : s) {
        if (c == 'H') {
            ch++;
        }
    }
    
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        string t = s;
        int cur = 0;
        int x = (i - 1 + n) % n;
        int y = i;
        for (int j = 0; j < ch; j++) {
            if (t[y] == 'T') {
                while (t[x] == 'T') {
                    x--;
                    if (x < 0) {
                        x += n;
                    }
                }
                swap(t[x], t[y]);
                cur++;
            }
            y++;
            if (y == n) {
                y = 0;
            }
        }
        ans = min(ans, cur);
    }

    cout << ans;
    return 0;
}