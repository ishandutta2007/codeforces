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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(c, n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        scid(x);
        m[-x]++;
    }

    for (int i = 0; i < c; i++) {
        m[-i]++;
        int s = c;
        int last = s + 1;
        while (s > 0) {
            auto it = m.upper_bound(-last);
            if (it == m.end()) {
                break;
            }
            int t = min(it->second, s / (-it->first));
            s += t * it->first;
            last = min(-it->first, s + 1);
        }
        if (s != 0) {
            cout << i;
            return 0;
        }
        if (--m[-i] == 0) {
            m.erase(-i);
        }
    }

    cout << "Greed is good";

    return 0;
}