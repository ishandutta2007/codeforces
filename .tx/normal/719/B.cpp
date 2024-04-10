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

int toc(char a, char to) {
    return a == to ? 0 : 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scids(s);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] == 'b' ? 0 : 1;
    }

    int ans = 1e9;

    for (int it = 0; it < 2; it++) {
        int w[2] = {0, 0};
        for (int i = 0; i < n; i++) {
            if (a[i] != (i + it) % 2) {
                w[a[i]]++;
            }
        }
        ans = min(ans, max(w[0], w[1]));
    }

    cout << ans;


    return 0;
}