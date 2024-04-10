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

lint MOD = 1e9 + 7;

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scids(s);
    lint cb = 0;
    lint ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'b') {
            cb++;
        } else {
            ans += cb;
            cb *= 2;
        }
        ans %= MOD;
        cb %= MOD;
    }

    cout << ans;
    
    return 0;
}