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

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

int a[111111];

int n, m;

int mm(int x) {
    return (x % m + m) % m; 
}

int mpow(int a, int p) {
    int res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(m, n);
    
    set<int> as;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        as.insert(a[i]);
    }
    
    if (n == 1 || n == m) {
        cout << a[0] << " " << min(m - 1, 1);
        return 0;
    }
    
    if (n == 2) {
        cout << a[0] << " " << mm(a[1] - a[0]);
        return 0;
    }
    
    int mg = -1;
    if (2 * n > m) {
        mg = m - n;
        n = 0;
        for (int i = 0; i < m; i++) {
            if (as.find(i) == as.end()) {
                a[n++] = i;
            }
        }
        as.clear();
        for (int i = 0; i < n; i++) {
            as.insert(a[i]);
        }
    }
    
    int d = mm(a[1] - a[0]);
    int cd = 0;
    for (int i = 0; i < n; i++) {
        if (as.find(mm(a[i] - d)) != as.end()) {
            cd++;
        }
    }
    
    d = 1LL * d * mpow(n - cd, m - 2) % m;
    
    int cl = 0;
    int ll = a[0];
    int x = a[0];
    
    while (as.find(mm(x - d)) != as.end()) {
        cl++;
        x = mm(x - d);
        ll = x;
    }
    
    x = a[0];
    int cr = 0;
    while (as.find(mm(x + d)) != as.end()) {
        cr++;
        x = mm(x + d);
    }
    
    if (cl + cr != n - 1) {
        cout << -1;
        return 0;
    }
    
    if (mg != -1) {
        ll = (ll + 1LL * mg * d) % m;
    }
    
    cout << ll << " " << d;
    

    return 0;
}