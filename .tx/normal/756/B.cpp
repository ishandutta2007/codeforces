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

int t[111111];
int d[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(t[i]);
    }
    d[0] = 20;
    for (int i = 1; i < n; i++) {
        d[i] = d[i - 1] + 20;
        
        int x = upper_bound(t, t + i - 1, t[i] - 90) - t;
        d[i] = min(d[i], (x == 0 ? 0 : d[x - 1]) + 50);
        
        x = upper_bound(t, t + i - 1, t[i] - 1440) - t;
        d[i] = min(d[i], (x == 0 ? 0 : d[x - 1]) + 120);
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        cout << d[i] - c << "\n";
        c = d[i];
    }
    
    return 0;
}