#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int n = 1; ; n++) {
        int ptr = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) a[i] = i;
        vector <int> b(n);
        function<void(int,int)> mergesort = [&] (int l, int r) {
            if (r - l <= 1) {
                return;
            }
            int m = (l + r) / 2;
            mergesort(l, m);
            mergesort(m, r);
            int i = l, j = m, k = l;
            while (i < m && j < r) {
                if (s[ptr] == '0') {
                    b[k] = a[i];
                    i++;
                } else {
                    b[k] = a[j];
                    j++;
                }
                ptr++;
                k++;
            }
            while (i < m) {
                b[k] = a[i];
                i++, k++;
            }
            while (j < r) {
                b[k] = a[j];
                j++, k++;
            }
            for (int p = l; p < r; p++) {
                a[p] = b[p];
            }
        };
        mergesort(0, n);
        if (ptr == (int) s.size()) {
            cout << n << endl;
            vector <int> c(n);
            for (int i = 0; i < n; i++) c[a[i]] = i;
            for (int i = 0; i < n; i++) cout << c[i] + 1 << ' ';
            cout << endl;
            return 0;
        }
    }
}