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
    string t = "";
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                t = s[i] + t;                
            } else {
                t = t + s[i];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 0) {
                t = s[i] + t;
            } else {
                t = t + s[i];
            }
        }
    }
    
    cout << t;

    return 0;
}