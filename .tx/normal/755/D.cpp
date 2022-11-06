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

int a[1111111];

int get(int r) {
    int res = 0; 
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += a[r];
    }
    return res;
}

int get(int l, int r) {
    int res = get(r);
    if (l > 0) {
        res -= get(l - 1);
    }
    return res;
}

void add(int i, int x) {
    for (; i < 1111111; i |= i + 1) {
        a[i] += x;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, k);
    if (k * 2 > n) {
        k = n - k;
    }
    
    lint cur = 1;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int y = x + k;
        int t = 0;
        if (y <= n) {
            t = get(x + 1, y - 1);
        } else {
            t = (x == n - 1 ? 0 : get(x + 1, n - 1)) + get(0, y - n - 1);
        }
        cur += t + 1;
        cout << cur << " ";
        add(x, 1);
        add(y % n, 1);
        x = y % n;
    }
    
    

    return 0;
}