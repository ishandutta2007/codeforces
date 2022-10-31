#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T >
T abs(T x) {
    return x > 0 ? x : -x;
}

template < typename T >
T sqr(T x) {
    return x * x;
}

const int maxn = 10000005;

int cnt[maxn];
int s[maxn], a[maxn];
ll ans = 0;
int k;

void rec(int l, int r) {
    if (l == r) {
        return;
    }

    int c = (l + r) >> 1;
    rec(l, c);
    rec(c + 1, r);

    int pl = c;
    int ml = 0;

    int mr = 0;
    for (int i = c + 1; i <= r; i++) {
        mr = max(mr, a[i]);
        while (pl >= l && max(a[pl], ml) <= mr) {
            ml = max(a[pl], ml);
            cnt[s[pl - 1]]++;
            pl--;
        }

        if (pl != c) {
            int need = (k + (s[i] - (mr % k))) % k;
            ans += cnt[need];
        }
    }


    for (int i = pl + 1; i <= c; i++) {
        cnt[s[i - 1]]--;
    }

    int pr = c + 1;

    mr = a[c + 1];
    ml = 0;
    for (int i = c; i >= l; i--) {
        ml = max(ml, a[i]);
        while (pr <= r && max(a[pr], mr) < ml) {
            mr = max(a[pr], mr);
            cnt[s[pr]]++;
            pr++;
        }

        if (pr != c + 1) {
            int need = (s[i - 1] + ml) % k;
            ans += cnt[need];
        }
    }

    for (int i = c + 1; i < pr; i++) {
        cnt[s[i]]--;
    }
}



int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        s[i] = (s[i - 1] + a[i]) % k;
    }

    rec(1, n);

    cout << ans << endl;

    return 0;
}