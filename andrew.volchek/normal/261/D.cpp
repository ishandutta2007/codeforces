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

    int k, n, bm, t;
    scanf("%d %d %d %d", &k, &n, &bm, &t);
    while (k--) {
        vector<int> cc;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            a.pb(x);
            cc.pb(x);
        }
        sort(cc.begin(), cc.end());
        cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
        for (int &x : a) {
            x = lower_bound(cc.begin(), cc.end(), x) - cc.begin();
        }
        int ub = (int)cc.size() + 2;
        vector<int> f(ub, 0);
        for (int i = 0; i < min(t, ub); i++) {
            for (int x : a) {
                int y = f[x] + 1;
                for (int j = x + 1; j < ub; j++) {
                    if (f[j] >= y) {
                        break;
                    }
                    f[j] = y;
                }
            }
        }
        cout << *max_element(f.begin(), f.end()) << endl;
    }
    return 0;
}