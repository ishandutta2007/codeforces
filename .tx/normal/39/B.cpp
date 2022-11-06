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
    int cur = 1;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x == cur) {
            ans.push_back(i);
            cur++;
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << 2001 + i << " ";
    }

    return 0;
}