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

int a[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scids(s, t);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        scid(x);
        --x;
        a[x] = i;
    }

    int l = 0, r = n;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        int j = 0;
        for (int i = 0; i < n && j < t.size(); i++) {
            if (a[i] >= m && s[i] == t[j]) {
                j++;
            }
        }
        if (j == t.size()) {
            l = m;
        } else {
            r = m;
        };
    }

    cout << l;

    return 0;
}