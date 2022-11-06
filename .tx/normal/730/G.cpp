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

lint x[222];
lint y[222];

bool cross(lint x1, lint y1, lint x2, lint y2) {
    return max(x1, x2) <= min(y1, y2);
}

bool cross(int i, int j) {
    return cross(x[i], y[i], x[j], y[j]);
}

int p[222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    lint c = 0;
    for (int i = 0; i < n; i++) {
        sci(x[i], y[i]);
        y[i] += x[i] - 1;
        p[i] = i;
    }

    for (int i = 1; i < n; i++) {
        bool ok = true;
        sort(p, p + i, [&](int l, int r) {
            return x[l] < x[r];
        });
        for (int j = 0; j < i; j++) {
            if (cross(i, j)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            lint a = c - x[i] + 1;
            x[i] += a;
            y[i] += a;
            for (int j = 0; j < i; j++) {
                if (cross(i, p[j])) {
                    a = y[p[j]] - x[i] + 1;
                    x[i] += a;
                    y[i] += a;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << x[i] << " " << y[i] << "\n";
    }

    return 0;
}