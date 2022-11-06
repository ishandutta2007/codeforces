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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scids(s);
    s += "_";
    n++;

    int mx = 0;
    int cins = 0;

    bool in = false;

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            int l = i - last - 1;
            mx = max(mx, l);
            last = i;
            in = true;
        } else if (s[i] == ')') {
            int l = i - last - 1;
            if (l != 0) {
                cins++;
            }
            in = false;
            last = i;
        } else if (s[i] == '_') {
            int l = i - last - 1;
            if (l != 0) {
                if (in) {
                    cins++;
                } else {
                    mx = max(mx, l);
                }
            }
            last = i;
        }
    }

    cout << mx << " " << cins;

    return 0;
}