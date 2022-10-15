#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T> T abs(T x) { return x < 0? -x : x; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = (int)1e+5 + 7;

int a[MAXN];
int s[MAXN];
int n, q;

void modify(int x, int d)
{
    a[x] += d;
    for (int i = x; i <= n; i += i & -i) {
        s[i] += d;
    }
}

int findsum(int l, int r)
{
    //cerr << l << " " << r << endl;
    if (l != 1) {
        return findsum(1, r) - findsum(1, l - 1);
    }
    int res = 0;
    for (int i = r; 1 <= i; i -= i & -i) {
        //cerr << i << endl;
        res += s[i];
    }
    //cerr << " = " << res << endl;
    return res;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    cin >> n >> q;
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; ++i) {
        modify(i, 1);
    }
    int begin, end, dir;
    begin = 1;
    end = n;
    dir = 1;
    while (q--) {
        int t;
        cin >> t;
        int length = abs(begin - end) + 1;
        //for (int i = 0; i < length; ++i) {
            //cout << a[begin + i * dir] << " ";
        //}
        //cout << endl;
        if (t == 1) {
            int p;
            cin >> p;
            if (p * 2 > length) {
                swap(end, begin);
                dir = -dir;
                p = length - p;
            }
            for (int i = 0; i < p; ++i) {
                modify(
                    begin + dir * (p - 1) + (p - i) * dir,
                    a[begin + dir * i]
                );
            }
            begin += dir * p;
        } else {
            int l, r;
            cin >> l >> r;
            l += 1;
            l = begin + (l - 1) * dir;
            r = begin + (r - 1) * dir;
            if (l > r) {
                swap(l, r);
            }
            cout << findsum(l, r) << endl;
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}