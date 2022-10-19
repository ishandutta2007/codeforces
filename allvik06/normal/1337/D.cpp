#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 8e18;
int right(vector <int> &a, int x) {
    int l = -1, r = a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] >= x) {
            r = m;
        }
        else {
            l = m;
        }
    }
    if (r == a.size()) return -1;
    return a[r];
}

int left(vector <int> &a, int x) {
    int l = -1, r = a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    if (l == -1) return -1;
    return a[l];
}
int tern(vector <int> &a, int x) {
    int l = -1, r = a.size();
    while (r - l > 1) {
        int len = r - l - 1;
        int m = (int)ceil((double)len / (double)3);
        int m1 = l + m, m2 = r - m;
        if (a[m1] * a[m1] - a[m1] * x < a[m2] * a[m2] - a[m2] * x) {
            r = m2;
        }
        else {
            l = m1;
        }
    }
    if (l == -1) return a[r] * a[r] - a[r] * x;
    else if (r == a.size()) return a[l] * a[l] - a[l] * x;
    else return min(a[r] * a[r] - a[r] * x, a[l] * a[l] - a[l] * x);
}

int f(int a, int b, int c) {
    return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}
signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> a(n), b(m), c(k);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int j = 0; j < m; ++j) {
            cin >> b[j];
        }
        for (int i = 0; i < k; ++i) {
            cin >> c[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int minn = INF;
        for (int i = 0; i < n; ++i) {
            int l = left(b, a[i]), r = right(b, a[i]);
            if (l != -1) {
                int tmp = tern(c, l + a[i]);
                minn = min(minn, 2 * tmp + a[i] * a[i] + l * l + (a[i] - l) * (a[i] - l));
            }
            if (r != -1) {
                int tmp = tern(c, r + a[i]);
                minn = min(minn, 2 * tmp + a[i] * a[i] + r * r + (a[i] - r) * (a[i] - r));
            }
            l = left(c, a[i]);
            r = right(c, a[i]);
            if (l != -1) {
                int tmp = tern(b, l + a[i]);
                minn = min(minn, 2 * tmp + a[i] * a[i] + l * l + (a[i] - l) * (a[i] - l));
            }
            if (r != -1) {
                int tmp = tern(b, r + a[i]);
                minn = min(minn, 2 * tmp + a[i] * a[i] + r * r + (a[i] - r) * (a[i] - r));
            }
        }
        cout << minn << "\n";
    }
}