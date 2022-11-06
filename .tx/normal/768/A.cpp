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

    scid(n);
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        scid(x);
        a[x]++;
    }
    int ans = n;
    ans -= a.begin()->second;
    ans -= a.rbegin()->second;
    cout << max(ans, 0);

    return 0;
}