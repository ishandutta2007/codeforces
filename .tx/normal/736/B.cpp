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

int ds[7];

bool is_prime(int n) {
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ds[2] = 1;
    ds[3] = 1;
    ds[4] = 2;
    ds[5] = 1;
    ds[6] = 2;
    
    scid(n);
    if (n < 7) {
        cout << ds[n];
        return 0;
    }
    
    if (is_prime(n)) {
        cout << 1;
        return 0;
    }
    
    if (n & 1) {
        if (is_prime(n - 2)) {
            cout << 2;
            return 0;
        }
        cout << 3;
        return 0;
    }
    
    cout << 2;

    return 0;
}