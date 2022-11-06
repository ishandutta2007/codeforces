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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    vector<int> a(n + 1);
    int g;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (i == 0) {
            g = a[i];
        } else {
            g = gcd(g, a[i]);
        }
        a[i] &= 1;
    }

    if (g != 1) {
        cout << "YES\n0";
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ans++;
            if (a[i + 1] == 0) {
                ans++;
            }
            a[i + 1] = 0;
        }
    }

    cout << "YES\n";
    cout << ans;

    return 0;
}