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

int a[2222];
int cnt[2222];
int cn[2222];
int oa[2222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        scid(x);
        --x;
        if (x < m) {
            cnt[x]++;
        }
        a[i] = x;
        oa[i] = x;
    }

    for (int k = n; k >= 0; k--) {
        memcpy(a, oa, sizeof(a));
        for (int i = 0; i < m; i++) {
            cn[i] = k - cnt[i];
        }
        int ln = 0;
        int xc = 0;
        for (int i = 0; i < n; i++) {
            while (ln < m && cn[ln] <= 0) {
                ln++;
            }
            if (ln == m) {
                break;
            }

            if (a[i] >= m) {
                xc++;
                a[i] = ln;
                cn[ln]--;
            } else if (cn[a[i]] < 0) {
                cn[ln]--;
                cn[a[i]]++;
                a[i] = ln;
                xc++;
            }
        }
        if (*max_element(cn, cn + m) <= 0) {
            cout << k << " " << xc << "\n";
            for (int i = 0; i < n; i++) {
                cout << a[i] + 1 << " ";
            }
            return 0;
        }

    }


    return 0;
}