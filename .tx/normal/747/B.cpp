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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scids(s);
    if (n % 4 != 0) {
        cout << "===";
        return 0;
    }
    
    for (char c : s) {
        cnt[c]++;
    }
    
    string t = "ATGC";
    
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            continue;
        }
        int mc = 0;
        for (int j = 1; j < 4; j++) {
            if (cnt[t[j]] < cnt[t[mc]]) {
                mc = j;
            }
        }
        s[i] = t[mc];
        cnt[t[mc]]++;
    }

    for (int i = 0; i < 4; i++) {
        if (cnt[t[i]] != n / 4) {
            cout << "===";
            return 0;
        }
    }
    cout << s;
    
    return 0;
}