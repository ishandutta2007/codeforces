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

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int ms[22222];
int c[22222];
int ac[22222];
int a[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, k);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        ac[a[i]]++;
    }
    
    int m = 0;
    for (int i = 0; i < (1 << 14); i++) {
        if (__builtin_popcount(i) == k) {
            ms[m++] = i;
        }
    }
    
    for (int i = 0; i <= 1e4; i++) {
        for (int j = 0; j < m; j++) {
            c[i] += ac[i ^ ms[j]];
        }
    }
    
    lint ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (k == 0) {
            ans += ac[a[i]] - 1;
        } else {
            ans += c[a[i]];
        }
    }
    
    cout << ans / 2;

    return 0;
}