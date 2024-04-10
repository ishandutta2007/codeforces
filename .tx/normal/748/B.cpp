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

char p[256];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s, t);
    int n = s.size();
    set<pair<char, char>> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (p[s[i]] != 0 && p[s[i]] != t[i]) {
                cout << -1;
                return 0;
            }
            if (p[t[i]] != 0 && p[t[i]] != s[i]) {
                cout << -1;
                return 0;
            }
            p[s[i]] = t[i];
            p[t[i]] = s[i];
            ans.insert({min(t[i], s[i]), max(t[i], s[i])});
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (p[s[i]] != 0) {
            s[i] = p[s[i]];
        }
    }
    
    if (s != t) {
        cout << -1;
        return 0;
    }
    
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}