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

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int f[111111];
int g[111111];
int h[111111];

int p[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    memset(p, -1, sizeof(p));
    int m = 0;
    for (int i = 0; i < n; i++) {
        sci(f[i]);
        --f[i];
        if (p[f[i]] == -1) {
            h[m] = f[i];
            p[f[i]] = m;
            m++;
        }
    }

    for (int i = 0; i < n; i++) {
        g[i] = p[f[i]];
    }

    for (int i = 0; i < n; i++) {
        if (h[g[i]] != f[i]) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (g[h[i]] != i) {
            cout << -1;
            return 0;
        }
    }

    cout << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << g[i] + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++) {
        cout << h[i] + 1 << " ";
    }




    return 0;
}