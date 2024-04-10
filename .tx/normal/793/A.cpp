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

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scidl(n, k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    int mn = *min_element(a.begin(), a.end());
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] -= mn;
        if (a[i] % k != 0) {
            cout << -1;
            return 0;
        }
        ans += a[i] / k;
    }

    cout << ans;

    return 0;
}