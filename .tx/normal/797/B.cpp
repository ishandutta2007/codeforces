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

    scid(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    sort(a.rbegin(), a.rend());

    if (a[0] <= 0) {
        for (int i : a) {
            if (i & 1) {
                cout << i;
                return 0;
            }
        }
        assert(false);
    }

    int s = 0;
    for (int i : a) {
        if (i <= 0) {
            break;
        }
        s += i;
    }

    if (s & 1) {
        cout << s;
        return 0;
    }

    int ans = -1e9;

    for (int i : a) {
        if (i > 0 && i % 2 == 1) {
            ans = max(ans, s - i);
        } else if (i < 0 && (i & 1)) {
            ans = max(ans, s + i);
        }
    }

    cout << ans;

    return 0;
}