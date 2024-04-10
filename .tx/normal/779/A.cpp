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

template <typename T, typename Cmp = std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int a[6];
int b[6];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[x]++;
    }
    for (int i = 0; i < n; i++) {
        scid(x);
        b[x]++;
    }
    
    int s = 0;
    for (int i = 1; i <= 5; i++) {
        if ((a[i] + b[i]) % 2 != 0) {
            cout << -1;
            return 0;
        }
        s += abs(a[i] - (a[i] + b[i]) / 2);
    }
    
    cout << (s + 1) / 2;
    

    return 0;
}