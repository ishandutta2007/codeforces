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

int a[1111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scids(s);
    s = 'L' + s + 'R';
    string t = s;
    s = "";
    for (char c : t) {
        if (c != '=') {
            s += c;
        }
    }
    int on = n;
    n = s.size() - 1;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'L' && s[i] == 'R') {
            a[i] = 1;
        }
    }
    
    for (int t = 1; t < n; t++) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                continue;
            }
            bool ok = true;
            if (s[i - 1] == 'R' && (a[i - 1] == 0 || a[i - 1] == t + 1)) {
                ok = false;
            }
            if (s[i] == 'L' && (a[i + 1] == 0 || a[i + 1] == t + 1)) {
                ok = false;
            }
            if (ok) {
                a[i] = t + 1;
            }
        }
    }
    
    int x = 1;
    for (int i = 1; i < t.size(); i++) {
        char c = t[i];
        cout << a[x] << " ";
        if (c != '=') {
            x++;
        }
        if (x > n) {
            break;
        }
    }
    
    return 0;
}