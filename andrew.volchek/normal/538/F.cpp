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
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

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

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 2e5 + 5;

int ft[maxn];

void inc(int i) {
    while (i < maxn) {
        ft[i]++;
        i = i | (i + 1);
    }
}

int get(int r) {
    int res = 0;
    while (r >= 0) {
        res += ft[r];
        r = (r & (r + 1)) - 1;
    }
    return res;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

int a[maxn];


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    vector<pair<int,int>> b;

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        b.pb(mp(a[i], i));
    }

    sort(b.begin(), b.end());

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && b[j].fst == b[i].fst) {
            j++;
        }

        for (int h = i; h < j; h++) {
            int v = b[h].snd;
            for (int k = 1; k <= n - 1 && k * (v - 1) + 2 <= n; k++) {
                int l = k * (v - 1) + 2, r = min(n, k * v + 1);
                ans[k] += get(l, r);
            }
        }

        for (int h = i; h < j; h++) {
            inc(b[h].snd);
        }

        i = j - 1;
    }

    for (int i = 1; i <= n - 1; i++) {
        if (i > 1) {
            printf(" ");
        }

        printf("%d", ans[i]);
    }

    return 0;
}