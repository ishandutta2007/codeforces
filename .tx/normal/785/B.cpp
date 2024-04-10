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

pair<int, int> a[222222];
pair<int, int> b[222222];

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i].first, a[i].second);
    }

    int a1 = 0, a2 = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first > a[a1].first) {
            a1 = i;
        }
        if (a[i].second < a[a2].second) {
            a2 = i;
        }
    }

    scid(m);
    for (int i = 0; i < m; i++) {
        sci(b[i].first, b[i].second);
    }

    int b1 = 0, b2 = 0;
    for (int i = 1; i < m; i++) {
        if (b[i].first > b[b1].first) {
            b1 = i;
        }
        if (b[i].second < b[b2].second) {
            b2 = i;
        }
    }

    int ans = 0;
    ans = max(ans, a[a1].first - b[b2].second);
    ans = max(ans, b[b1].first - a[a2].second);
    cout << ans;

    return 0;
}