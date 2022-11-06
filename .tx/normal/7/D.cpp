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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s);
    int n = s.length();
    string t(s.rbegin(), s.rend());
    t = s + "#" + t;
//    cerr << t << endl;
    int nt = t.size();
    vector<int> z(nt);
    int l = 0, r = 0;
    for (int i = 1; i < nt; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < nt && t[i + z[i]] == t[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }

    t = s;
    reverse(t.begin(), t.end());

//    for (int i = 0; i < nt; i++) {
//        cerr << z[i] << " ";
//    }
//    cerr << endl;

    vector<lint> d(n, 0);
    d[0] = 1;
    for (int i = 1; i < n; i++) {
        if (z[nt - i / 2 + 1 - 1 - (i + 1) / 2 - 1] >= (i + 1) / 2) {
//            cerr << i << endl;
            d[i] = d[(i - 1) / 2] + 1;
        }
    }

    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d[i];
//        cerr << d[i] << " ";
    }
    cout << ans;

    return 0;
}