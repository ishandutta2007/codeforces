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

    scid(n, k);
    scids(s);
    
    int p = s.find('G');
    for (int i = p; i < n; i += k) {
        if (s[i] == '#') {
            break;
        }
        if (s[i] == 'T') {
            cout << "YES";
            return 0;
        }
    }
    
    for (int i = p; i >= 0; i -= k) {
        if (s[i] == '#') {
            break;
        }
        if (s[i] == 'T') {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";

    return 0;
}