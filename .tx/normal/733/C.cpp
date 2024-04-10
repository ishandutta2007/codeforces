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

int a[555];
int b[555];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    scid(m);
    for (int i = 0; i < m; i++) {
        sci(b[i]);
    }

    if (n < m) {
        cout << "No";
        return 0;
    }

    int ai = 0;
    vector<pair<int, char> > ans;
    while (ai < n && ai < m) {
        int s = 0;
        int i = ai;
        for (; i < n && s < b[ai]; i++) {
            s += a[i];
        }
        if (s != b[ai]) {
            cout << "NO";
            return 0;
        }
        for (int j = ai; j + 1 < i; j++) {
            int mx = *max_element(a + ai, a + i - (j - ai));
//            int mp = max_element(a + ai, a + i - (j - ai)) - a;
            int mp = -1;
            for (int t = ai; t + 1 < i - (j - ai); t++) {
                if ((a[t] == mx || a[t + 1] == mx) && a[t] != a[t + 1]) {
                    if (a[t] < a[t + 1]) {
                        ans.push_back({t + 1, 'L'});
                    } else {
                        ans.push_back({t, 'R'});
                    }
                    mp = t;
                    break;
                }
            }
            if (mp == -1) {
                cout << "NO";
                return 0;
            }
            a[mp] += a[mp + 1];
            --n;
            for (int t = mp + 1; t < n; t++) {
                a[t] = a[t + 1];
            }
        }
        ai++;
    }

    if (ai == n && ai == m) {
        cout << "YES\n";
        for (auto i : ans) {
            cout << i.first + 1 << " " << i.second << "\n";
        }
    } else {
        cout << "NO";
    }

    return 0;
}