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

    set<string> a, b, both;
    scid(n, m);
    for (int i = 0; i < n; i++) {
        scids(s);
        a.insert(s);
    }
    for (int i = 0; i < m; i++) {
        scids(s);
        if (a.find(s) != a.end()) {
            a.erase(s);
            both.insert(s);
        } else {
            b.insert(s);
        }
    }
    
    int ca = a.size() + (both.size() + 1) / 2;
    int cb = b.size() + both.size() / 2;
    
    if (ca > cb) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}