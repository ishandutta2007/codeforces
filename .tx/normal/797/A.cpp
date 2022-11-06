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

    scid(n, k);
    vector<int> a;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            a.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        a.push_back(n);
    }
    if (a.size() < k) {
        cout << -1;
        return 0;
    }
    while (a.size() > k) {
        int x = a.back(); a.pop_back();
        int y = a.back(); a.pop_back();
        a.push_back(x * y);
    }

    for (int i : a) {
        cout << i << " ";
    }

    return 0;
}