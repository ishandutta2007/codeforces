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

bool gl[256];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s);
    s += 'A';
    int n = s.size();
    int last = -1;
    int ans = -1;
    gl['A'] = true;
    gl['E'] = true;
    gl['I'] = true;
    gl['O'] = true;
    gl['U'] = true;
    gl['Y'] = true;
    for (int i = 0; i < n; i++) {
        if (gl[s[i]]) {
            ans = max(ans, i - last);
            last = i;
        }
    }

    cout << ans;

    return 0;
}