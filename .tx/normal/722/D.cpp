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

int a[55555];
int ans[55555];

int get_p(int x) {
    int p = 0;
    for (int j = 0; j < 30; j++) {
        if ((x >> j) & 1) {
            p = j;
        }
    }
    return p;
}

bool cmp(int x, int y) {
    int px = get_p(x);
    int py = get_p(y);
    if (px != py) {
        return px < py;
    }
    return x > y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        s.insert(a[i]);
    }
//    unordered_set<int> used(n * 3);
//    for (int i = 0; i < n; i++) {
//        int p = 0;
//        int x = a[i];
//        for (int j = 0; j < 30; j++) {
//            if ((x >> j) & 1) {
//                p = j;
//            }
//        }
//        int c = 1;
//        while (used.find(c) != used.end()) {
//            --p;
//            c = (c << 1) | ((x >> p) & 1);
//        }
//        used.insert(c);
//        ans[i] = c;
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << ans[i] << " ";
//    }

    while (true) {
        int c = *s.rbegin();
        s.erase(c);
        int x = c >> 1;
        while (x > 0 && s.find(x) != s.end()) {
            x >>= 1;
        }
        if (x != 0) {
            s.insert(x);
        } else {
            s.insert(c);
            break;
        }
    }

    for (int i : s) {
        cout << i << " ";
    }

    return 0;
}