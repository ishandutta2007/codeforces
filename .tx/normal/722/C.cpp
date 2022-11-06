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

struct Dsu {
    int *a;
    int *r;

    Dsu(int n) {
        a = new int[n];
        r = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
            r[i] = 1;
        }
    }

    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;;
        }

        if (r[x] > r[y]) {
            a[y] = x;
        } else {
            a[x] = y;
            if (r[x] == r[y]) {
                r[y]++;
            }
        }
    }
};

lint s[111111];
int a[111111];
int p[111111];
lint ans[111111];
bool good[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    for (int i = 0; i < n; i++) {
        sci(p[i]);
        --p[i];
    }

    Dsu dsu(n);

    lint mx = 0;

    for (int i = n - 1; i >= 0; i--) {
        ans[i] = mx;
        int x = p[i];
        good[x] = true;
        s[x] = a[x];
        if (x + 1 < n && good[x + 1]) {
            lint ns = s[dsu.get(x + 1)] + s[dsu.get(x)];
            dsu.unite(x, x + 1);
            s[dsu.get(x)] = ns;
        }
        if (x > 0 && good[x - 1]) {
            lint ns = s[dsu.get(x - 1)] + s[dsu.get(x)];
            dsu.unite(x, x - 1);
            s[dsu.get(x)] = ns;
        }

        mx = max(mx, s[dsu.get(x)]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}