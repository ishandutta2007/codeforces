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
typedef long double ldouble;

int a[111111];
int b[111111];

lint d[111111];


ldouble cross(ldouble x1, ldouble y1, ldouble x2, ldouble y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    for (int i = 0; i < n; i++) {
        sci(b[i]);
    }

    vector<int> ch;
    ch.push_back(0);
    int cur = 0;
    for (int i = 1; i < n; i++) {
        d[i] = d[ch[cur]] + 1LL * b[ch[cur]] * a[i];
        while (cur + 1 < ch.size()) {
            lint td = d[ch[cur + 1]] + 1LL * b[ch[cur + 1]] * a[i];
            if (td <= d[i]) {
                d[i] = td;
                cur++;
            } else {
                break;
            }
        }

        while (ch.size() > 1) {
            int p1 = ch[ch.size() - 2];
            int p2 = ch.back();
            if (cross(b[i] - b[p2], d[i] - d[p2], b[p2] - b[p1], d[p2] - d[p1]) <= 1e-9) {
                ch.pop_back();
            } else {
                break;
            }
        }
        ch.push_back(i);
        cur = min(cur, (int) ch.size() - 1);
    }

    cout << d[n - 1];



    return 0;
}