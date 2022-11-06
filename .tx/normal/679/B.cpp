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

int p[1111];

void go(lint x) {
    if (x == 0) {
        return;
    }
    lint l = (lint) floor(pow(x, 1.0 / 3));
    while (l * l * l <= x) {
        l++;
    }
    --l;

    go(x - l * l * l);
    cout << l << " ";
}

int goc(int x) {
    if (x == 0) {
        return 0;
    }
    int l = (int) floor(pow(x, 1.0 / 3));
    while (l * l * l <= x) {
        l++;
    }
    --l;
    return goc(x - l * l * l) + 1;
}

lint p3(lint x) {
    return x * x * x;
}

#define DBs

int main() {
    init_cin

#ifndef DB
    lint m;
    cin >> m;
#endif

#ifdef DB

    for (int m = 1; m <= 1000; m++) {

        int mx = 0;
        int ma = -1;
        for (int i = 1; i <= m; i++) {
            int t = goc(i);
            if (t >= mx) {
                mx = t;
                ma = i;
            }
        }

#endif
        lint cs = 0;
        lint ci = 1;
        vector<lint> a;
        while (true) {
            while (cs + p3(ci) >= p3(ci + 1)) {
                ci++;
                if (ci >= 75000) {
                    break;
                }
            }
            if (ci >= 75000) {
                break;
            }
            if (cs + p3(ci) > m) {
                break;
            }
            cs += p3(ci);
            a.push_back(ci);
        }

        for (int i = (int) a.size() - 1; i >= 0; i--) {
            lint ci = a[i];
            while (true) {
                a[i]++;
                bool ok = true;
                cs = 0;
                for (lint j : a) {
                    cs += p3(j);
                }
                if (cs > m) {
                    ok = false;
                }
                for (int j = a.size() - 1; j >= 0; j--) {
                    if (p3(a[j] + 1) <= cs) {
                        ok = false;
                        break;
                    }
                    cs -= p3(a[j]);
                }

                if (!ok) {
                    a[i]--;
                    break;
                }
            }
        }



        cs = 0;
        for (lint i : a) {
            cs += p3(i);
        }

#ifndef DB
    cout << a.size() << " " << cs;
    cout << "\n";
//    go(cs);
#endif

#ifdef DB

        if (mx != a.size() || ma != cs) {
            cout << "m: " << m << endl;
            cout << mx << "\n";
            cout << ma << ": ";
            go(ma);
            cout << endl;
            cout << endl;

            cout << a.size() << " " << cs << endl;
            for (int i : a) {
                cout << i << " ";
            }
            cout << endl;

            return 0;
        }
    }
    cout << "OK";
#endif

//    lint m;
//    cin >> m;
//    lint cs = 0;
//    lint ci = 1;
//    vector<lint> a;
//    while (true) {
//        while (cs + p3(ci) >= p3(ci + 1)) {
//            ci++;
//        }
//        if (cs + p3(ci) > m) {
//            break;
//        }
//        cs += p3(ci);
//        a.push_back(ci);
//    }
//
//    for (int i = (int) a.size() - 1; i >= 0; i--) {
//        lint ci = a[i];
//        while (true) {
//            lint ncs = cs - p3(ci) + p3(ci + 1);
//            if (ncs > m) {
//                break;
//            }
//            cs = ncs;
//            ci++;
//            a[i]++;
//        }
//    }
//
//    cout << a.size() << " " << cs;


    return 0;
}