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

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}


vector<int> comb(vector<int> a, vector<int> b) {
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        res.pb(a[b[i]]);
    }
    return res;
}


int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif


    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a(n), q(n), qi(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        x--;
        q[i] = x;
        qi[x] = i;
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        x--;
        a[i] = x;
    }


    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    if (p == a) {
        printf("NO");
        return 0;
    }

    if (a == q && a == qi) {
        if (k == 1) {
            printf("YES");
        } else {
            printf("NO");
        }
        return 0;
    }

    auto x = p;
    for (int i = 1; i <= k; i++) {
        x = comb(x, q);
        if (x == a && (k - i) % 2 == 0) {
            printf("YES");
            return 0;
        }
    }

    x = p;
    for (int i = 1; i <= k; i++) {
        x = comb(x, qi);
        if (x == a && (k - i) % 2 == 0) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");

    return 0;
}