#include <bits/stdc++.h>

using namespace std;

template<typename T>
void sci(T &t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T &t, Ts &... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int r[55][55];
bool w[55][55];

int n;

bool norm(int n);

int get(int i, int j) {
    if (w[i][j]) {
        return r[i][j];
    }
    w[i][j] = true;
    w[j][i] = true;
    cout << "? " << i + 1 << " " << j + 1 << "\n";
    cout.flush();
    char c;
    cin >> c;
    if (c == '<') {
        r[i][j] = -1;
        r[j][i] = 1;
    } else if (c == '=') {
        r[i][j] = 0;
        r[j][i] = 0;
    } else {
        r[i][j] = 1;
        r[j][i] = -1;
    }

//    while (norm(n));
    return r[i][j];
}

int p[55];

bool norm(int n) {
    bool res = false;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (w[i][j]) {
                    continue;
                }
                if (w[i][k] && w[k][j]) {
                    if (r[i][k] == 0) {
                        r[i][j] = r[k][j];
                        w[i][j] = true;
                    } else if (r[k][j] == 0) {
                        r[i][j] = r[i][k];
                        w[i][j] = true;
                    } else if (r[i][k] == r[k][j]) {
                        r[i][j] = r[i][k];
                        w[i][j] = true;
                    }
                }
                res |= w[i][j];
            }
        }
    }
    return res;
}

pair<int, int> ans(int l, int r) {
    if (l == r) {
        return {l, r};
    }
    if (l + 1 == r) {
        int t = get(l, r);
        if (t < 0) {
            return {l, r};
        }
        return {r, l};
    }

    pair<int, int> al, ar;

    if (r - l <= 3) {
        int m = (l + r) >> 1;
        al = ans(l, m);
        ar = ans(m + 1, r);
    } else {
        al = ans(l, l + 3);
        ar = ans(l + 4, r);
    }

    int t1 = get(al.first, ar.first);
    pair<int, int> res;
    if (t1 < 0) {
        res.first = al.first;
    } else {
        res.first = ar.first;
    }

    int t2 = get(al.second, ar.second);

    if (t2 > 0) {
        res.second = al.second;
    } else {
        res.second = ar.second;
    }

    return res;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(31);

    scid(t);
    for (int i = 0; i < t; i++) {
        sci(n);

        memset(w, false, sizeof(bool) * 55 * 55);

        auto p = ans(0, n - 1);
        cout << "! " << p.first + 1 << " " << p.second + 1 << "\n";
        cout.flush();
    }

    return 0;
}