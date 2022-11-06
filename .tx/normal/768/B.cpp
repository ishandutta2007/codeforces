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

lint n, l, r;
int ans = 0;

void go(lint x, lint y, lint n) {
    if (x > y || y < l || r < x) {
        return;
    }
    lint nl = (y - x) / 2;
    if (x + nl >= l && x + nl <= r) {
        ans += n % 2;
    }
    if (x != y) {
        go(x, x + nl - 1, n / 2);
        go(x + nl + 1, y, n / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sci(n, l, r);
    --l;
    --r;
    lint on = n;
    int c = 0;
    do {
        n /= 2;
        c++;
    } while (n > 0);
    n = on;

    go(0, (1LL << c) - 2, n);
    cout << ans;


    return 0;
}