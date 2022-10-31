#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> ll round(T x) { return x < 0 ? x - 0.5 : x + 0.5; }
template<class T> void minimize(T & x, const T & y) {
    if (y < x) x = y;
}
template<class T> void maximize(T & x, const T & y) {
    if (x < y) x = y;
}
template<class T> T abs(T x) { return x < 0 ? -x : x; }

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
#endif

    int n;
    cin >> n;

    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> cnt(n + 1);
    vector<int> res(n + 1);

    for (int l = 0; l < n; l++) {
        fill(cnt.begin(), cnt.end(), 0);
        int bestColor = 0;
        for (int r = l; r < n; r++) {
            int x = t[r];
            cnt[x]++;
            if (cnt[x] > cnt[bestColor] || (cnt[x] == cnt[bestColor] && x < bestColor)) {
                bestColor = x;
            }
            res[bestColor]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i + 1 == (int)res.size()];
    }

    return 0;
}