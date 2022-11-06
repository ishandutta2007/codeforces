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

int cnt[256];
string name = "Bulbasaur";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s);
    for (char c : s) { 
        cnt[c]++;
    }
    int ans = 1e9;
    for (char c : name) {
        ans = min(ans, cnt[c]);
    }
    ans = min(ans, cnt['a'] / 2);
    ans = min(ans, cnt['u'] / 2);
    cout << ans;

    return 0;
}