#include <bits/stdc++.h>

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

int a[111111];

int main() {
    sciid(n, k);
    map<int, int> cnt;
    set<int> one;
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = x;
        if (cnt[x] == 1) {
            one.erase(x);
        }
        cnt[x]++;
        if (cnt[x] == 1) {
            one.insert(x);
        }
        if (i + 1 >= k) {
            if (i >= k) {
                x = a[i - k];
                if (cnt[x] == 1) {
                    one.erase(x);
                }
                cnt[x]--;
                if (cnt[x] == 1) {
                    one.insert(x);
                }
            }
            if (!one.empty()) {
                cout << *one.rbegin() << "\n";
            } else {
                cout << "Nothing\n";
            }
        }
    }

    return 0;
}