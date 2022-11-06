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

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    scid(n);
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x != i + 1) {
            s.insert(x);
        } else {
            ans++;
        }
    }
    ans += s.size() / 2;
    cout << ans;

    return 0;
}