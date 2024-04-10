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

    scid(n);
    scids(s);

    int ans = n;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == '>' && s[i + 1] == '<') {
            int l = i;
            while (l >= 0 && s[l] == '>') {
                ans--;
                l--;
            }
            int r = i + 1;
            while (r  < n && s[r] == '<') {
                ans--;
                r++;
            }
            i = r - 1;
        }
    }

    cout << ans;



    return 0;
}