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

    scidl(b1, q, l, m);

    if (abs(b1) > l) {
        cout << 0;
        return 0;
    }

    set<lint> bad;
    for (int i = 0; i < m; i++) {
        scid(x);
        bad.insert(x);
    }

    int ans = 0;
    set<lint> was;
    while (abs(b1) <= l) {
        was.insert(b1);
        if (bad.count(b1) == 0) {
            ans++;
        }
        b1 *= q;
        if (was.count(b1)) {
            if (ans == 0) {
                cout << 0;
            } else if (q == 0 && bad.count(0)) {
                cout << ans;
            } else {
                cout << "inf";
            }
            return 0;
        }
    }

    cout << ans;

    return 0;
}