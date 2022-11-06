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

const int R = 0;
const int L = 1;
const int U = 2;
const int D = 3;

bool w[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scids(s);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            if (w[L]) {
                ans++;
                fill(w, w + 4, false);
            }
            w[R] = true;
        } else if (s[i] == 'L') {
            if (w[R]) {
                ans++;
                fill(w, w + 4, false);
            }
            w[L] = true;
        } else if (s[i] == 'U') {
            if (w[D]) {
                ans++;
                fill(w, w + 4, false);
            }
            w[U] = true;
        } else { // s[i] == 'D'
            if (w[U]) {
                ans++;
                fill(w, w + 4, false);
            }
            w[D] = true;
        }
    }
    
    cout << ans;

    return 0;
}