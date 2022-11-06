#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>
#include <fstream>

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

int solve_stupid() {
    ifstream in("input.txt");
    int n, k;
    in >> n >> k;
    if (n == 1) {
        return 0;
    }
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        in >> x;
        a.insert(x);
    }

    for (int i = 0; i < k; i++) {
        int x = *a.rbegin();
        a.erase(a.find(x));
        x--;
        a.insert(x);
        x = *a.begin();
        a.erase(a.find(x));
        x++;
        a.insert(x);
    }

    in.close();

    return (*a.rbegin()) - (*a.begin());
}

void gen() {
    ofstream out("input.txt");

    int n = rand() % 10 + 1;
    int k = rand() % 100;

    out << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
        out << rand() % 100 << " ";
    }

    out.close();
}

int a[555555];
int nb[555555];

int main() {
//srand(31);
//for (int ttt = 0; ttt < 1000; ttt++) {
//    gen();
//    int sss = solve_stupid();
//    cerr << sss << endl;
//    freopen("input.txt", "r", stdin);


    sciid(n, k);
    rea(a, n);
    random_shuffle(a, a + n);
    sort(a, a + n);
    reverse(a, a + n);
    lint s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }

    int l = 0, r = 1e9 + 11;

    while (l + 1 < r) {
        int m = (l + r) >> 1;
        lint tm = 0, ts = 0;
        for (int i = 0; i < n; i++) {
            tm += max(0, m - a[i]);
            ts += max(0, a[i] - m);
        }
        if (ts >= tm && tm <= k) {
            l = m;
        } else {
            r = m;
        }
    }

    int mn = l;

    l = (s + n - 1) / n - 1, r = 1e9;

    while (l + 1 < r) {
        int m = (l + r) >> 1;
        lint ts = 0;
        for (int i = 0; i < n; i++) {
            ts += max(0, a[i] - m);
        }
        if (ts <= k) {
            r = m;
        } else {
            l = m;
        }
    }

    int mx = r;

//    cerr << mn << " " << mx << endl;
    cout << mx - mn;
//    if (mx - mn != sss) {
//        return 1;
//    }

//    int l = 0, r = 1e9 + 11;
//    int ans = 1e9 + 100;
//
//    while (l + 1 < r) {
//        int m = (l + r) >> 1;
//        lint tk = 0;
//        for (int i = 0; i < n; i++) {
//            tk += max(0, a[i] - m);
//        }
//        if (tk > k) {
//            l = m;
//            continue;
//        }
//        lint ts = 0;
//        int cc = 0;
//        for (int i = 0; i < n; i++) {
//            if (a[i] <= m) {
//                ts += a[i];
//                cc++;
//            }
//        }
//
//        if (cc == 0) {
//            l = m;
//            continue;
//        }
//
//        int nm = a[n - 1];
//
//        for (int i = n - 1; tk > 0 && i >= 0; i--) {
//            lint ta = (a[i - 1] - a[i]) * (n - i);
//            if (ta >= tk) {
//                nm = a[i] + tk / (n - i);
//                break;
//            } else {
//                tk -= ta;
//            }
//        }
//
//        if (nm <= m) {
//            ans = min(ans, m - nm);
//            r = m;
//        } else {
//            l = m;
//        }
//    }
//
//    cout << ans;

//    lint ab = 0;
//
//    for (int i = 0; i < n; i++) {
//        lint t = (s + n - i - 1) / (n - i);
//        nb[i] = t;
//        s -= t;
//        ab += max(0, a[i] - nb[i]);
//    }
//
//    if (ab <= k) {
//        if (s % n == 0) {
//            cout << 0;
//        } else {
//            cout << 1;
//        }
//        return 0;
//    }
//
//    int ok = k;
//    int i = 0;
//
//    for (; ; i++) {
//        lint t = 1LL * (a[i] - a[i + 1]) * (i + 1);
//        if (t > k) {
//
//        }
//    }


//}


    return 0;
}