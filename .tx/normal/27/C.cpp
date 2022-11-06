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

int a[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }

    if (n <= 2) {
        cout << 0;
        return 0;
    }

    int st = 0;
    while (st + 1 < n && a[st] == a[st + 1]) {
        st++;
    }

    if (st + 1 == n) {
        cout << 0;
        return 0;
    }

    if (a[st] > a[st + 1]) {
        for (int i = 0; i < n; i++) {
            a[i] *= -1;
        }
    }

    for (int i = st + 1; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
            cout << 3 << "\n";
            cout << st + 1 << " " << i + 1 << " " << i + 2;
            return 0;
        }
    }

    cout << 0;


    return 0;
}