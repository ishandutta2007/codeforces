#include <bits/stdc++.h>

using namespace std;

long long mod = 1313131319;
long long p = 41;

struct Fenv {
    long long *a;
    int n;

    Fenv(int n_) {
        n = n_;
        a = new long long[n];
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
    }

    void add(int i, long long v) {
        for (; i < n; i |= (i + 1)) {
            a[i] = (a[i] + v + mod * mod) % mod;
        }
    }

    long long sum(int l, int r) {
        long long res = sum(r);
        if (l > 0) {
            res = (res - sum(l - 1) + mod * mod) % mod;
        }
        return res;
    }

    long long sum(int i) {
        long long res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            res = (res + a[i]) % mod;
        }
        return res;
    }
};

int n;
long long *pPow;
Fenv *h;
Fenv *ih;

bool isPaly(int l, int r) {
    long long hh = h->sum(l, r);
    long long ihh = ih->sum(n - 1 - r, n - 1 - l);
    hh = hh * pPow[n - 1 - r];
    ihh = ihh * pPow[l];
    return hh == ihh || (hh % mod) == (ihh) % mod;
}

void solve()  {
    int d;
    scanf("%d\n", &d);
    if (d == 1) {
        puts("Impossible");
        return;
    }
    string s;
    getline(cin, s);
    n = s.length();
    pPow = new long long[n];
    pPow[0] = 1;
    for (int i = 1; i < n; i++) {
        pPow[i] = pPow[i - 1] * p % mod;
    }
    h = new Fenv(n);
    for (int i = 0; i < n; i++) {
        h->add(i, (s[i] - 'a' + 1) * pPow[i]);
    }
    ih = new Fenv(n);
    for (int i = 0; i < n; i++) {
        ih->add(i, (s[n - 1 - i] - 'a' + 1) * pPow[i]);
    }
    int pos = n - 1;
    for (int i = d - 1; i < n; i++) {
        if (isPaly(i - d + 1, i)) {
            pos = i;
            break;
        }
        if (i >= d && isPaly(i - d, i)) {
            pos = i;
            break;
        }
    }
    for (; pos >= 0; pos--) {
        bool p1 = (pos >= d - 1) && isPaly(pos - d + 2, pos - 1);
        bool p2 = (pos >= d) && isPaly(pos - d + 1, pos - 1);
        for (char j = (char) (s[pos] + 1); j <= 'z'; j++) {
            if (p1 && j == s[pos - d + 1]) {
                continue;
            }
            if (p2 && j == s[pos - d]) {
                continue;
            }
            h->add(pos, (j - s[pos]) * pPow[pos]);
            ih->add(n - 1 - pos, (j - s[pos]) * pPow[n - 1 - pos]);
            s[pos] = j;
            goto pf;
        }
    }
    pf:
    if (pos == -1) {
        puts("Impossible");
        return;
    }
    for (; ++pos < n; ) {
        bool p1 = (pos >= d - 1) && isPaly(pos - d + 2, pos - 1);
        bool p2 = (pos >= d) && isPaly(pos - d + 1, pos - 1);
        for (char j = 'a'; j <= 'z'; j++) {
            if (p1 && (j == s[pos - d + 1])) {
                continue;
            }
            if (p2 && (j == s[pos - d])) {
                continue;
            }
            h->add(pos, (j - s[pos]) * pPow[pos]);
            ih->add(n - 1 - pos, (j - s[pos]) * pPow[n - 1 - pos]);
            s[pos] = j;
            // cout << pos << " " << j << endl;
            break;
        }
    }
    cout << s << endl;
}

int main() {
    solve();
    return 0;
}