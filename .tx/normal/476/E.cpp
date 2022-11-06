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

int d[2222][2222];
int a[2222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s, p);
    memset(a, -1, sizeof(a));
    int n = s.size();
    int m = p.size();
    for (int i = 0; i < n; i++) {
        int is = i;
        int ip = 0;
        while (is < n && ip < m) {
            if (s[is] == p[ip]) {
                ip++;
            }
            is++;
        }
        if (ip == m) {
            a[i] = is;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            d[i + 1][j] = max(d[i + 1][j], d[i][j]);
            d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j]);
            if (a[i] != -1) {
                d[a[i]][j + a[i] - i - m] = max(d[a[i]][j + a[i] - i - m], d[i][j] + 1);
            }
        }
    }

    for (int i = n; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

//    for (int i = 0; i <= n; i++) {
//        cout << d[n][i] << " ";
//    }

    return 0;
}