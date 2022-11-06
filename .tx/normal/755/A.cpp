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

bool pr[1111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    fill(pr, pr + 1111111, true);
    pr[1] = false;
    for (int i = 2; i < 1111111; i++) {
        if (pr[i]) {
            for (int j = i + i; j < 1111111; j += i) {
                pr[j] = false;
            }
        }
    }
    
    scid(n);
    for (int i = 1; ; i++) {
        if (!pr[n * i + 1]) {
            cout << i;
            return 0;
        }
    }
    

    return 0;
}