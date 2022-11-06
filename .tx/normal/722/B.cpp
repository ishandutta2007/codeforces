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

int p[111];
int c[111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(p[i]);
    }
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (char j : s) {
            if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u' || j == 'y') {
                c[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] != c[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}