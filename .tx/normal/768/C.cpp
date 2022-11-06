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

int a[2][1111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, k, x);
    for (int i = 0; i < n; i++) {
        scid(t);
        a[0][t]++;
    }

    for (int i = 0; i < k; i++) {
        int cr = i & 1;
        int nx = cr ^ 1;
        memset(a[nx], 0, sizeof(int) * 1024);
        int f = 1;
        for (int j = 0; j < 1024; j++) {
            int hm;
            if (f && (a[cr][j] & 1)) {
                hm = (a[cr][j] >> 1) + 1;
            } else {
                hm = a[cr][j] >> 1;
            }
            f ^= a[cr][j] & 1;
            a[nx][j] += a[cr][j] - hm;
            a[nx][j ^ x] += hm;
        }
    }

    int mx = -1e9;
    int mn = 1e9;
    for (int i = 0; i < 1024; i++) {
        if (a[k & 1][i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    cout << mx << " " << mn;


    return 0;
}