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

int l2[222222];

struct Sparse {
    int* sp[22];

    Sparse(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < 22; i++) {
            sp[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            sp[0][i] = a[i];
        }
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int get(int l, int r) {
        int len = r - l + 1;
        return min(sp[l2[len]][l], sp[l2[len]][r - (1 << l2[len]) + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 2; i <= n; i++) {
        if (i & (i - 1)) {
            l2[i] = l2[i - 1];
        } else {
            l2[i] = l2[i - 1] + 1;
        }
    }

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        a[i] = -a[i];
    }

    for (int i = 0; i < n; i++) {
        sci(b[i]);
    }

    Sparse spa(a);
    Sparse spb(b);

    lint ans = 0;

    for (int i = 0; i < n; i++) {
        int l = -1, r = i + 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            int mx = -spa.get(m, i);
            int mn = spb.get(m, i);
            if (mx <= mn) {
                r = m;
            } else {
                l = m;
            }
        }

        int a1 = r;
        l = -1, r = i + 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            int mx = -spa.get(m, i);
            int mn = spb.get(m, i);
            if (mx < mn) {
                r = m;
            } else {
                l = m;
            }
        }

        int a2 = r;
        ans += a2 - a1;
    }

    cout << ans;




    return 0;
}