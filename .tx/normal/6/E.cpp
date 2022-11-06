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
    deque<int> mn, mx;
    int aa = 0;
    vector<pair<int, int> > ps;
    int last = -1; //
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = x;
        while (!mn.empty() && x < mn.back()) {
            mn.pop_back();
        }
        mn.push_back(x);
        while (!mx.empty() && x > mx.back()) {
            mx.pop_back();
        }
        mx.push_back(x);
        while (mx.front() - mn.front() > k) {
            ++last;
            if (mn.front() == a[last]) {
                mn.pop_front();
            }
            if (mx.front() == a[last]) {
                mx.pop_front();
            }
        }
        int clen = i - last;
        if (clen > aa) {
            aa = clen;
            ps.clear();
        }
        if (clen == aa) {
            ps.push_back({last + 1, i});
        }
    }

    cout << aa << " " << ps.size() << "\n";
    for (auto& i : ps) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}