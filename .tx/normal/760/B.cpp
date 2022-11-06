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

lint f(lint s, lint n) {
    if (n <= s) {
        return n * (s + s - n + 1) / 2;
    }
    return s * (s + 1) / 2 + n - s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, k);
    --k;
    
    int l = 1, r = m + 1;
    while (l + 1 < r) {
        int md = (l + r) >> 1;
        lint s = f(md, k + 1) + f(md, n - k) - md;
//        for (int i = 0; i < n; i++) {
//            s += max(1, md - abs(k - i)); 
//        }
        if (s > m) {
            r = md;
        } else {
            l = md;
        }
    }
    cout << l;

    return 0;
}