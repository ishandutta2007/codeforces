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


int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("rects.in", "r", stdin);
    //freopen("rects.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    ll m = -1e18, p = -1e18, ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        m = max(m, ans - x);
        p = max(p, ans + x);
        ans = max(ans, m + x);
        ans = max(ans, p - x);
    }

    cout << ans << endl;

    return 0;
}