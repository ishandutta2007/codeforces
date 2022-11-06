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

int t[55];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, l);
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        sci(t[i]);
    }
    for (int i = 1; i < n; i++) {
        a[i] = t[i] - t[i - 1];
    }
    a[0] = l - t[n - 1] + t[0];
    
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        sci(t[i]);
    }
    for (int i = 1; i < n; i++) {
        b[i] = t[i] - t[i - 1];
    }
    b[0] = l - t[n - 1] + t[0];
    
    for (int i = 0; i < n; i++) {
        if (a == b) {
            cout << "YES";
            return 0;
        }
        rotate(a.begin(), a.begin() + 1, a.end());
    }
    
    cout << "NO";

    return 0;
}