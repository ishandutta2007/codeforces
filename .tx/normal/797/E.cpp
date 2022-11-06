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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

const int BS = 300;

int a[111111];
int cop[111111][BS];

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }

    for (int k = 1; k < BS; k++) {
        for (int i = n - 1; i >= 0; i--) {
            if (i + a[i] + k >= n) {
                cop[i][k] = 1;
            } else {
                cop[i][k] = cop[i + a[i] + k][k] + 1;
            }
        }
    }

    scid(q);
    for (int iq = 0; iq < q; ++iq) {
        scid(p, k);
        --p;
        if (k < BS) {
            cout << cop[p][k] << "\n";
        } else {
            int ans = 0;
            while (p < n) {
                p += a[p] + k;
                ans++;
            }
            cout << ans << "\n";
        }
    }


    return 0;
}