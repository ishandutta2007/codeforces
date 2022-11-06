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

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(k, a, b);
    if (a > b) {
        swap(a, b);
    }
    if (a < k && b % k != 0) {
        cout << -1;
        return 0;
    }
    int ans = a / k + b / k;
    if (ans == 0) {
        ans = -1;
    }
    cout << ans;

    return 0;
}