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

vector<int> a[555555];
int s[1111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, c);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i].resize(x);
        for (int j = 0; j < x; j++) {
            sci(a[i][j]);
            --a[i][j];
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        int p = -1;
        for (int j = 0; j < min(a[i].size(), a[i + 1].size()); j++) {
            if (a[i][j] != a[i + 1][j]) {
                p = j;
                break;
            }
        }
        if (p == -1 && a[i].size() > a[i + 1].size()) {
            cout << -1;
            return 0;
        }
        if (p == -1) {
            s[0]++;
            s[c]--;
            continue;
        }
        if (a[i][p] < a[i + 1][p]) {
            if (a[i][p] != 0) {
                int x = c - a[i][p];
                s[x]++;
                s[c]--;
            }
            int x = c - a[i + 1][p];
            s[0]++;
            s[x]--;
        } else {
            int x = c - a[i][p];
            int y = c - a[i + 1][p];
            s[x]++;
            s[y]--;
        }
    }

    int cur = 0;
    for (int i = 0; i < c; i++) {
        cur += s[i];
        if (cur == n - 1) {
            cout << i;
            return 0;
        }
    }
    cout << -1;


    return 0;
}