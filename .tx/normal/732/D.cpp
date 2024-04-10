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

int d[111111];
int rt[111111];
int last[111111];
int a[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        sci(d[i]);
        --d[i];
    }
    for (int i = 0; i < m; i++) {
        sci(a[i]);
    }

    fill(last, last + m, n);
    for (int i = n - 1; i >= 0; i--) {
        if (d[i] != -1) {
            rt[i] = last[d[i]];
            last[d[i]] = i;
        }
    }

    int l = 0, r = n + 1;
    while (l + 1 != r) {
        int md = (l + r) >> 1;
        int s = 0;
        int cnt_pass = 0;
        for (int i = 0; i < md; i++) {
            if (d[i] == -1 || rt[i] < md) {
                s++;
            } else {
                s -= a[d[i]];
                cnt_pass++;
            }
            if (s < 0) {
                break;
            }
        }
        if (s < 0 || cnt_pass < m) {
            l = md;
        } else {
            r = md;
        }
    }

    if (r == n + 1) {
        cout << -1;
    } else {
        cout << r;
    }




    return 0;
}