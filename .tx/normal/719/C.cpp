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

    scid(n, t);
    scids(s);
    bool f = false;
    bool wd = false;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == '.') {
            continue;
        }
        int nx = i + 1;
        if (s[nx] == '.') {
            wd = true;
            nx++;
        }
        if (!wd) {
            continue;
        }
        if (s[nx] >= '5') {
            s = s.substr(0, nx);
            s[i]++;
            --t;
            n = nx;
            f = true;
            break;
        }
    }

    if (!f) {
        cout << s;
        return 0;
    }

    cerr << s << endl;

    for (int i = n - 1; t > 0 && i > 0; i--) {
        if (s[i] == '.') {
            break;
            continue;
        }
        int nx = i - 1;
        if (s[nx] == '.') {
            nx--;
        }
        if (s[i] >= '5') {
            t--;
            s[i] = '0';
            s[nx]++;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if (s[i] == '.') {
            continue;
        }
        int nx = i - 1;
        if (s[nx] == '.') {
            nx--;
        }
        if (s[i] > '9') {
            s[i] = '0';
            s[i - 1]++;
        }
    }

    if (s[0] > '9') {
        cout << 1;
        s[0] = '0';
    }
    while (s.size() > 2) {
        if (s.back() == '0') {
            s.pop_back();
        } else {
            break;
        }
    }
    if (s.back() == '.') {
        s.pop_back();
    }
    cout << s;


    return 0;
}