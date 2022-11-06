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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

string s[55];
string os[55];
int a[55];

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(s[i]);
        os[i] = s[i];
    }

    int ans = 1e9;
for (int t = 0; t < n; t++) {
    for (int i = 0; i < n; i++) {
        s[i] = os[i];
    }
    memset(a, 0, sizeof(a));
    rotate(os, os + 1, os + n);
    int cur = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 50; j++) {
            if (s[i] == s[0]) {
                break;
            }
            a[i]++;
            rotate(s[i].begin(), s[i].begin() + 1, s[i].end());
//            cout << s[i] << endl;
        }
        if (a[i] == 50) {
            cout << -1;
            return 0;
        }
        cur += a[i];
    }

    ans = min(ans, cur);

    for (int i = 0; i < 50; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            a[j] = (a[j] + 1) % s[0].size();
            cur += a[j];
        }
        ans = min(ans, cur);
    }
}
    cout << ans;
    return 0;
}