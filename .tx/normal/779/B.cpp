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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, k);
    if (n == 0) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    int len = 0;
    while (n > 0 && k > 0) {
        len++;
        if (n % 10 == 0) {
            k--;
        } else {
            ans++;
        }
        n /= 10;
    }
    
    if (k != 0) {
        cout << len - 1;
    } else {
        cout << ans;
    }

    return 0;
}