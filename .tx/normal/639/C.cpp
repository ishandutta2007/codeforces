#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>
#include <fstream>
#include <ctime>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

lint a[444444];
lint oa[444444];

void gen() {
    ofstream out("input.txt");
    int n = 20;
    int k = 10000;
    out << n << " " << k << endl;
    for (int i = 0; i < n - 10; i++) {
        out << 0 << " ";
    }
    for (int i = max(0, n - 10); i <= n; i++) {
        out << rand() % 11 - 5 << " ";
    }
    out.close();
}

int stupid() {
    ifstream in("input.txt");
    int n, k;
    in >> n >> k;
    n++;
    vector<int> a(n);
    lint s = 0;
    for (int i = 0; i < n; i++) {
        in >> a[i];
        s += a[i] * (1LL << i);
    }
    if (s == 0) {
        return -1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = -k; j <= k; j++) {
            lint add = 1LL * (j - a[i]) * (1LL << i);
            if (s + add == 0) {
                if (i + 1 != n || j != 0)
                    ans++;
            }
        }
    }
    in.close();
    return ans;
}

#define TESTS

int main() {
    init_cin
#ifdef TEST
    srand(time(0));
for (int tn = 0; tn < 1000; tn++) {
    gen();
    int sans = stupid();
    ifstream cin("input.txt");
    memset(a, 0, sizeof(a));
#endif
    int n, k;
    cin >> n >> k;
    n++;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        oa[i] = a[i];
    }
    lstart:
    bool cool0 = true;
    for (int i = 0; i < n; i++) {
        if (i + 2 == n) {
            for (int j = 0; j <= i; j++) {
                if (a[j] != 0) {
                    cool0 = false;
                }
            }
        }
        if (a[i] > 0) {
            a[i + 1] += a[i] / 2;
            a[i] %= 2;
        } else {
            lint t = (-a[i] + 1) / 2;
            a[i] += t * 2;
            a[i + 1] -= t;
        }
    }

    int x = n + 5;
    while (a[x] == 0) {
        x--;
    }
    if (a[x] < 0) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            oa[i] = -oa[i];
            a[i] = oa[i];
        }
        cerr << "goto!!" << endl;
        goto lstart;
    }
    while (a[x] > 1) {
        a[x + 1] += a[x] / 2;
        a[x] %= 2;
        x++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        lint c = oa[i] + k;
        lint pp = 1;
        int pc = 0;
        int j;
        for (j = i; pc <= 40 && pp <= c && c > 0 && j <= x; j++, pc++) {
            if (a[j] == 1) {
                c -= pp;
            }
            pp *= 2;
        }
        if (j > x && c >= 0) {
            ans++;
        }

        if (a[i] == 1) {
            break;
        }
    }

    if (cool0) {
        ans--;
    }

    cout << ans << "\n";

#ifdef TEST
    if (sans != -1 && ans != sans) {
        cout << "ans: " << ans << endl << "sans: " << sans << endl;
        return 0;
    }
    cin.close();
}
#endif

    return 0;
}