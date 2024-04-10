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

template <typename T, typename Cmp = std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

pair<int, int> a[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, k);
    for (int i = 0; i < n; i++) {
        sci(a[i].first);
    }
    for (int i = 0; i < n; i++) {
        sci(a[i].second);
    }
    sort(a, a + n, [](auto x, auto y) { return x.second - x.first > y.second - y.first;});
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < k || a[i].first < a[i].second) {
            ans += a[i].first;
        } else {
            ans += a[i].second;
        }
    }
    
    cout << ans;
    

    return 0;
}