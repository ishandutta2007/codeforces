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

#define double long double

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

using pt = pair<lint, lint>;

struct Segment {
    pt a, b;
};

Segment p[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    map<pt, int> m;

    bool ok = true;

    for (int i = 0; i < 4; i++) {
        scidl(x1, y1, x2, y2);
        if (x1 != x2 && y1 != y2) {
            ok = false;
        }
        if (x1 == x2 && y1 == y2) {
            ok = false;
        }
        p[i] = Segment{make_pair(x1, y1), make_pair(x2, y2)};
        m[p[i].a]++;
        m[p[i].b]++;
    }


    for (int i = 0; i < 4; i++) {
        if (m[p[i].a] != 2 || m[p[i].b] != 2) {
            ok = false;
        }

        for (int j = i + 1; j < 4; j++) {
            if ((p[i].a.first == p[i].b.first) != (p[j].a.first == p[j].b.first)) {
                continue;
            }
            if (p[i].a.first == p[i].b.first && p[j].a.first == p[i].a.first) {
                ok = false;
            }
            if (p[i].b.second == p[i].a.second && p[j].a.second == p[i].a.second) {
                ok = false;
            }
        }
    }

    if (ok) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}