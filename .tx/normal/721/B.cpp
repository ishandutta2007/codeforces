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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int cnt[111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    scid(n, k);
    for (int i = 0; i < n; i++) {
        scids(s);
        cnt[s.size()]++;
    }
    scids(s);
    int x = s.size();
    int a = 0;
    for (int i = 0; i < x; i++) {
        a += cnt[i];
    }

    int mn = a + (a / k) * 5 + 1;
    int mx = a + cnt[x] - 1 + (a + cnt[x] - 1) / k * 5 + 1;

    cout << mn << " " << mx;


    return 0;
}