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

int main() {
    init_cin
    vector<bool> pos;
    bool p = true;
    int cp = 0;
    int n;
    while (true) {
        string s;
        cin >> s;
        if (s == "=") {
            cin >> n;
            break;
        }
        if (s == "+") {
            p = true;
        }
        if (s == "-") {
            p = false;
        }
        if (s == "?") {
            pos.push_back(p);
            if (p) {
                cp++;
            }
        }
    }

    int cn = pos.size() - cp;

    int mx = cp * n - cn;
    int mn = -cn * n + cp;

    if (n > mx || n < mn) {
        cout << "Impossible";
        return 0;
    }

    cout << "Possible\n";

    int c = 0;
    for (int i = 0; i < pos.size(); i++) {
        p = pos[i];
        if (p) {
            cp--;
            int l = n - c;
            int d = cp - cn;
            int t = min(n, max(1, l - d));
            c += t;
            if (i != 0) {
                cout << " + ";
            }
            cout << t;
        } else {
            cn--;
            int l = n - c;
            int d = cp - cn;
            int t = min(n, max(1, d - l));
            c -= t;
            cout << " - ";
            cout << t;
        }
    }
    cout << " = " << n;

    return 0;
}