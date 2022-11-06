#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        scid(x);
        s.insert(x);
        if (s.size() > 3) {
            cout << "NO";
            return 0;
        }
    }

    if (s.size() > 3) {
        cout << "NO";
        return 0;
    }
    if (s.size() < 3) {
        cout << "YES";
        return 0;
    }

    int a[3];
    for (int i = 0; i < 3; i++) {
        a[i] = *s.begin();
        s.erase(a[i]);
    }
    if (a[1] * 2 == (a[0] + a[2])) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}