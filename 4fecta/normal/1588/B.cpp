#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int a[100005];

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int ret;
    cin >> ret;
    if (ret == -1) abort();
    return ret;
}

int size(int x) {
    int lo = 2, hi = 1e9, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (mid * (mid - 1) / 2 < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int ch(int x) {
    return x * (x - 1) / 2;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tot = ask(1, n);
        int lo = 1, hi = n, mid, cnt;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            cnt = ask(1, mid);
            if (cnt == 0) lo = mid + 1;
            else if (cnt == tot) hi = mid;
            else break;
        }
        //mid is inside
        int cs = ask(1, mid - 1);
        int d = cnt - cs;
        int p1 = mid - d;
        int prev = 0;
        if (p1 > 1) prev = ask(1, p1 - 1);
        if (prev) { //p1 is j
            int sz = size(prev);
            int p2 = p1 - sz;
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                cnt = ask(1, mid);
                if (cnt == tot) hi = mid;
                else lo = mid + 1;
            }
            cout << "! " << p2 << " " << p1 << " " << lo << endl;
        } else { //p1 is i
            lo = p1;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                int inv = ask(p1, mid);
                if (size(inv) == mid - p1 + 1) lo = mid;
                else hi = mid - 1;
            }
            int p2 = lo + 1;
            int rem = tot - ch(p2 - p1);
            int p3 = p2 + size(rem) - 1;
            cout << "! " << p1 << " " << p2 << " " << p3 << endl;
        }
    }

    return 0;
}