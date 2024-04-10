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

    scidl(n, k);
    vector<lint> a;
    for (lint i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            if (i * i != n) {
                a.push_back(n / i);                
            }
        }
    }
    --k;
    if (k >= a.size()) {
        cout << -1;
        return 0;
    }
    nth_element(a.begin(), a.begin() + k, a.end());
    cout << a[k];
    

    return 0;
}