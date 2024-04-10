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

vector<int> a[22];
vector<int> b[22];

bool check(vector<int>& a) {
    int n = a.size();
    int p1 = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
            p1 = i;
            break;
        }
    }
    if (p1 == -1) {
        return true;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < a[p1]) {
            swap(a[i], a[p1]);
            break;
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scid(x);
            a[i].push_back(x);
        }
    }

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                b[i] = a[i];
                b[i][j1] = a[i][j2];
                b[i][j2] = a[i][j1];
                if (!check(b[i])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";


    return 0;
}