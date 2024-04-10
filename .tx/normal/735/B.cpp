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

int a[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    scid(n, n1, n2);
    
    if (n1 > n2) {
        swap(n1, n2);
    }
    
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    
    sort(a, a + n);
    reverse(a, a + n);
    
    double a1 = 0;
    for (int i = 0; i < n1; i++) {
        a1 += a[i];
    }
    a1 /= n1;
    
    double a2 = 0;
    for (int i = n1; i < n1 + n2; i++) {
        a2 += a[i];
    }
    a2 /= n2;
    
    cout << setprecision(11) << fixed << a1 + a2;

    return 0;
}