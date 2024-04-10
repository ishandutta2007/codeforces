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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, k);
    vector<lint> ps;
    if (k == 1) {
        ps.push_back(1);
    } else if (k == -1) {
        ps.push_back(-1);
        ps.push_back(1);
    } else {
        lint x = 1;
        while (abs(x) <= 1e15) {
            ps.push_back(x);
            x *= k;
        }
    }
    map<lint, int> m;
    m[0] = 1;
    lint ans = 0;
    lint s = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        s += x;
        for (lint p : ps) {
            auto it = m.find(s - p);
            if (it != m.end()) {
                ans += it->second;
            }
        }
        m[s]++;
    }

    cout << ans;

    return 0;
}