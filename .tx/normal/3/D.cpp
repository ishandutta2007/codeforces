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

int c[55555];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s);
    int n = s.size();
    if (n & 1) {
        cout << -1;
        return 0;
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            scid(x, y);
            if (x < y) {
                ans += x;
                s[i] = '(';
                c[i] = y - x;
            } else {
                ans += y;
                s[i] = ')';
                c[i] = x - y;
            }
        } else {
            c[i] = 1e9;
        }
    }
    
    
    for (int tt = 0; tt < 2; tt++) {
        set<pair<int, int> > l;
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] != 1e9 && s[i] == ')') {
                l.insert({c[i], i});
            }
            if (s[i] == '(') {
                b++;
            } else {
                b--;
            }
            if (b < 0) {
                if (l.empty()) {
                    cout << -1;
                    return 0;
                }
                auto pl = *l.begin();
                ans += pl.first;
                s[pl.second] = '(';
                l.erase(pl);
                b += 2;
            }
        }
        
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            s[i] = (s[i] == '(') ? ')' : '(';
        }
        reverse(c, c + n);
    }
    
    cout << ans << "\n" << s;

    return 0;
}