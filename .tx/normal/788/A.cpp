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

int a[111111];
lint b[111111];

lint get(int st, int n) {
    lint ans = -1e18;
    lint mn = 0;
    for (int i = st; i < n; i++) {
        ans = max(ans, b[i] - mn);
        mn = min<lint>(mn, b[i]);
    }
    return ans;
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    if (n == 2) {
        cout << abs(a[1] - a[0]);
        return 0;
    }

    for (int i = 0; i + 1 < n; i++) {
        b[i] = abs(a[i + 1] - a[i]);
        if (i & 1) {
            b[i] = -b[i];
        }
        if (i) {
            b[i] += b[i - 1];
        }
    }

    lint ans = get(0, n - 1);
    for (int i = 0; i + 1 < n; i++) {
        b[i] = -abs(a[i + 1] - a[i]);
        if (i & 1) {
            b[i] = -b[i];
        }
        if (i) {
            b[i] += b[i - 1];
        }
    }
    ans = max(ans, get(0, n - 1));
    cout << ans;

    return 0;
}