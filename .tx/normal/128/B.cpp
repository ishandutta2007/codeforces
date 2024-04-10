#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char s[111111];
int p[111111];
int c[111111];
int pn[111111];
int cn[111111];
int cnt[111111];

int n;

void deb() {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << endl;
}

lint slen[111111];

lint getS(int l, int r) {
    lint res = slen[r];
    if (l) {
        res -= slen[l - 1];
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%s", s);
    n = strlen(s) + 1;
    s[n - 1] = 0;
    scid(k);
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i < 256; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        p[--cnt[s[i]]] = i;
    }
    int cls = 1;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) {
            cls++;
        }
        c[p[i]] = cls - 1;
    }

    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) {
                pn[i] += n;
            }
        }
        memset(cnt, 0, cls * sizeof(int));
        for (int i = 0; i < n; i++) {
            ++cnt[c[pn[i]]];
        }
        for (int i = 1; i < cls; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cls = 1;
        cn[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (c[p[i]] != c[p[i - 1]] || c[(p[i] + (1 << h)) % n] != c[(p[i - 1] + (1 << h)) % n]) {
                cls++;
            }
            cn[p[i]] = cls - 1;
        }
        memcpy(c, cn, n *sizeof(int));
    }

    n--;
    for (int i = 0; i < n; i++) {
        p[i] = p[i + 1];
    }

    for (int i = 0; i < n; i++) {
        slen[i] = n - p[i];
        if (i) {
            slen[i] += slen[i - 1];
        }
    }

    --k;

    if (k >= 1LL * n * (n + 1) / 2) {
        cout << "No such line.";
        return 0;
    }

    int len = 1;
    int dl = 0, dr = n - 1;
    while (true) {
        while (dl < n && n - p[dl] < len) {
            dl++;
        }
        while (true) {
            int l = dl, r = dr + 1;
            while (l + 1 < r) {
                int m = (l + r) >> 1;
                int clen = n - p[m];
                if (clen >= len && s[p[m] + len - 1] == s[p[dl] + len - 1]) {
                    l = m;
                } else {
                    r = m;
                }
            }

            lint cb = getS(dl, l) - 1LL * (len - 1) * (l - dl + 1);
            if (k < cb) {
                dr = l;
                break;
            }
            dl = l + 1;
            k -= cb;
        }
        if (k < (dr - dl + 1)) {
            for (int i = 0; i < len; i++) {
                cout << s[p[dl] + i];
            }
            return 0;
        }
        k -= (dr - dl + 1);

        len++;
    }

    cerr << ":(";

    return 0;
}