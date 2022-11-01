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
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        x--;
        a[x] = i;
    }

    vector<int> c;

    for (int j = 0; j < n; j++) {
        int x;
        scanf("%d", &x);
        x--;
        c.pb(x);
        b[x] = j;
    }

    set<pair<int,int>> decr, incr;
    int deltaD = 0, deltaI = 0;


    for (int i = 0; i < n; i++) {
        if (b[i] >= a[i]) {
            decr.insert(mp(b[i] - a[i], i));
        } else {
            incr.insert(mp(a[i] - b[i], i));
        }
    }

    for (int i = 0; i < n; i++) {
        int ans = 1e9;
        if (decr.size()) {
            chmin(ans, decr.begin()->fst + deltaD);
        }

        if (incr.size()) {
            chmin(ans, incr.begin()->fst + deltaI);
        }

        printf("%d\n", ans);

        while (decr.size() && decr.begin()->fst + deltaD == 0) {
            auto c = *decr.begin();
            decr.erase(decr.begin());
            c.fst += deltaD;
            c.fst -= deltaI;
            incr.insert(c);
        }

        int x = c[i];

        assert(incr.count(mp(a[x] - 0 - deltaI, x)));
        incr.erase(mp(a[x] - 0 - deltaI, x));

        deltaD--;
        deltaI++;

        decr.insert(mp(n - 1 - a[x] - deltaD, x));
    }

    return 0;
}