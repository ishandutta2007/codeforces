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

int a[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, x);
    a[x] = 1;
    while (n % 6 != 0) {
        if (n % 2 == 0) {
            swap(a[1], a[2]);
        } else {
            swap(a[0], a[1]);
        }
        n--;
    }
    for (int i = 0; i < 3; i++) {
        if (a[i]) {
            cout << i;
        }
    }

    return 0;
}