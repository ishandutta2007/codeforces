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

int t[222222];

int main() {
    sciiid(n, k, q);
    rea(t, n);
    set<pair<int, int> > fs;
    set<int> ids;
    while (q-- > 0) {
        sciid(tp, id);
        --id;
        if (tp == 2) {
            if (ids.find(id) != ids.end()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            fs.insert({t[id], id});
            ids.insert(id);
            if (fs.size() > k) {
                pair<int, int> p = *fs.begin();
                fs.erase(p);
                ids.erase(p.second);
            }
        }
    }

    return 0;
}