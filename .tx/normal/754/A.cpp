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
    int nz = -1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        s += x;
        if (nz == -1 && s != 0) {
            nz = i;
        }
    }
    
    if (s != 0) {
        cout << "YES\n1\n1 " << n;
    } else if (nz == -1) {
        cout << "NO";
    } else {
        cout << "YES\n2\n";
        cout << "1 " << nz + 1 << "\n";
        cout << nz + 2 << " " << n << "\n";
    }

    return 0;
}