#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int a[33];

bool isPali(string& s, int from) {
    int n = s.length();
    int i = from, j = (from - 1 + n) % n;
    for (int tt = 0; tt * 2 < n; tt++) {
        if (s[i] != s[j]) {
            return false;
        }
        i = (i + 1) % n;
        j = (j - 1 + n) % n;
    }
    return true;
}

int slow() {
    scid(n);
    rea(a, n);

    string s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            s += (char) (i + 'a');
        }
    }

    int ans = -1;
    string as = "";

    do {
        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isPali(s, i)) {
                c++;
            }
        }
        if (c > ans || (c == ans && isPali(s, 0))) {
            ans = c;
            as = s;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << "\n" << as;
    return 0;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
pair<int, int> p[33];

void printPaly(int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j * 2 <= p[i].first; j++) {
            cout << (char) (p[i].second + 'a');
        }
    }
    if (p[0].first & 1) {
        cout << (char) (p[0].second + 'a');
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * 2 <= p[i].first; j++) {
            cout << (char) (p[i].second + 'a');
        }
    }
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if ((a.first & 1) == 1 && (b.first & 1) == 1) {
        return false;
    }
    if (a.first & 1) {
        return true;
    }
    if (b.first & 1) {
        return false;
    }
    return a.first < b.first;
}

int fast() {

    scid(n);
    int kOdd = 0;
    int nOdd = -1;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (a[i] & 1) {
            kOdd++;
            nOdd = i;
        }
        p[i] = {a[i], i};
    }
    sort(p, p + n, cmp);
    if (n == 1) {
        cout << a[0] << "\n";
        for (int i = 0; i < a[0]; i++) {
            cout << 'a';
        }
        return 0;
    }

    if (kOdd > 1) {
        cout << 0 << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[i]; j++) {
                cout << (char) (i + 'a');
            }
        }
        return 0;
    }

//    if (kOdd == 1) {
//        cout << 1 << "\n";
//        printPaly(n);
//        return 0;
//    }

    int gc = a[0];
    for (int i = 1; i < n; i++) {
        gc = gcd(gc, a[i]);
    }

    if (gc == 1) {
        cout << 1 << "\n";
        printPaly(n);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if ((gc & 1) == 0) {
            p[i].first /= (gc / 2);
        } else {
            p[i].first /= gc;
        }
    }

    cout << gc << "\n";
    int in = (gc % 2 == 0) ? gc / 2 : gc;
    for (int i = 0; i < in; i++) {
        printPaly(n);
    }

    return 0;
}

int main() {
    fast();
//    slow();


    return 0;
}