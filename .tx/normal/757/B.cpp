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

int cnt[111111];
int ans[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        cnt[x]++;
    }
    
    for (int i = 2; i < 111111; i++) {
        for (int j = i; j < 111111; j += i) {
            ans[i] += cnt[j];
        }
    }
    ans[1] = 1;
    
    cout << *max_element(ans, ans + 111111);
    

    return 0;
}