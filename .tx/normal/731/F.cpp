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

int cnt[222222];
lint ans[222222];
int a[222222];

const int MA = 200002;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        cnt[x]++;
        a[i] = x;
    }
    for (int i = 1; i <= MA; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = 1; i < MA; i++) {
        for (int j = i; j < MA; j += i) {
            ans[i] += 1LL * (cnt[min(MA, i + j - 1)] - cnt[j - 1]) * j;
        }
    }

    lint mx = 0;
    for (int i = 0; i < n; i++) {
//        cerr << a[i] << " " << ans[a[i]] << endl;
        mx = max(mx, ans[a[i]]);
    }

    cout << mx;

    return 0;
}